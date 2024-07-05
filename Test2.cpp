#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
  // Framebuffer-Datei öffnen
  int fd = open("/dev/fb0", O_RDWR);

  if (fd < 0) {
    perror("Fehler beim Öffnen des Framebuffers");
    return 1;
  }

  // Framebuffer-Größe abrufen
  struct fb_var_screeninfo screen_info;
  if (ioctl(fd, FBIOGET_VSCREENINFO, &screen_info) < 0) {
    perror("Fehler beim Abrufen der Framebuffer-Informationen");
    close(fd);
    return 1;
  }

  // Framebuffer-Speicher in den Speicher mappen
  void *fbptr = mmap(NULL, screen_info.xsize * screen_info.ysize * screen_info.bits_per_pixel / 8,
                    PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  if (fbptr == MAP_FAILED) {
    perror("Fehler beim Zuordnen des Framebuffers");
    close(fd);
    return 1;
  }

  // Rotes Pixel zeichnen
  unsigned char *pixel = (unsigned char *)fbptr + screen_info.xsize * 100 + 100 * screen_info.bits_per_pixel / 8;
  *pixel = 0xFF; // Rot
  *(pixel + 1) = 0x00; // Grün
  *(pixel + 2) = 0x00; // Blau

  // Framebuffer-Zuordnung aufheben
  munmap(fbptr, screen_info.xsize * screen_info.ysize * screen_info.bits_per_pixel / 8);

  // Framebuffer-Datei schließen
  close(fd);

  return 0;
}
