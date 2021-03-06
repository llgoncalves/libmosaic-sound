#include "include/volume.h"
#include <gtk/gtk.h>
#include <stdio.h>
mscsound_volume_t *volumeCopy;
static void mscsound_volume_event(GtkScaleButton *widget,
                                  GdkEventConfigure *event, gpointer data) {
  *(volumeCopy->output0) = gtk_scale_button_get_value(widget);
}
mscsound_volume_t *mscsound_create_volume(char *labelValue) {
  mscsound_volume_t *volume = malloc(sizeof(mscsound_volume_t));
  volume->output0 = calloc(1, sizeof(float));
  volumeCopy = volume;

  GtkWidget *volumeButton;
  GtkWidget *label;

  volume->widget = gtk_grid_new();

  label = gtk_label_new(labelValue);
  gtk_grid_attach(GTK_GRID((GtkWidget *)volume->widget), label, 1, 1, 1, 1);

  volumeButton = gtk_volume_button_new();
  gtk_grid_attach(GTK_GRID((GtkWidget *)volume->widget), volumeButton, 2, 1, 1,
                  1);
  g_signal_connect(volumeButton, "value-changed",
                   G_CALLBACK(mscsound_volume_event), &volume);

  return volume;
}
