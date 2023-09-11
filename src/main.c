
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <uxhw.h>

double read_samples(const char *filename);

int main(int argc, char *argv[]) {
  double Lift; // Lift Force [N]
  double CI;   // Lift Coefficient [no unit]
  double rho;  // Air Density [kg/m^3]
  double Aw;   // Wing Area [m^2]
  double Vw_squared;   // Relative Wind's velocity [m/s]
  double delta_pressure; // relative wind's pressure [N/m^2]

  CI = read_samples("samples-normal-CI.csv");
  printf("Lift Coefficient = %lf [1] \n", CI);

  rho = read_samples("samples-normal-rho.csv");
  printf("rho = %lf [Kg/m^3] \n", rho);

  Aw = read_samples("samples-normal-Wing-Area.csv");
  printf("Wing Area = %lf [m^2] \n", Aw);

  delta_pressure = read_samples("samples-uniform-delta-pressure.csv");
  printf("delta_pressure = %lf [N/m^2] \n", delta_pressure);


  
  Vw_squared = 2 * delta_pressure / rho;
  printf("Measured Wind Speed = %lf [m/s]\n", sqrt(Vw_squared));



  Lift = 0.5 * CI * rho * Aw * Vw_squared;
  printf("Lift Force = %lf [N]\n", Lift);

  return 0;
}

double read_samples(const char *path) {
  FILE *file;
  int n;
  double *samples;
  double val;

  file = fopen(path, "r");

  fscanf(file, "%d\n", &n);

  samples = malloc(n * sizeof(double));

  for (int i = 0; i < n; i++) {
    fscanf(file, "%lf\n", &samples[i]);
  }

  val = UxHwDoubleDistFromSamples(samples, n);

  fclose(file);
  free(samples);

  return val;
}
