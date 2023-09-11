
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
  double Vw;   // Relative Wind's velocity [m/s]
  double delta_pressure; // relative wind's pressure [N/m^2]

  // Read samples for Lift Coeffficient, randomly generated:
  // Normal distribution:  mean = 0.5, std_dev = 0.01 
  CI = read_samples("samples-normal-CI.csv");
  printf("Lift Coefficient = %lf [1] \n", CI);


  // Read samples for Air density, randomly generated:
  // Normal distribution:  mean = 1.3, std_dev = 0.1
  rho = read_samples("samples-normal-rho.csv");
  printf("rho = %lf [Kg/m^3] \n", rho);


  // Read samples for Wing Area, randomly generated:
  // Normal distribution:  mean = 20, std_dev = 0.01
  Aw = read_samples("samples-normal-Wing-Area.csv");
  printf("Wing Area = %lf [m^2] \n", Aw);


  // Pressure measured by Pitot Tube 
  // Uniform distribution:  mean = 24000, +/- 10%
  delta_pressure = read_samples("samples-uniform-delta-pressure.csv");
  printf("delta_pressure = %lf [N/m^2] \n", delta_pressure);


  // Calculated wind speed from measured delta in pressure:
  Vw = sqrt(2 * delta_pressure / rho);
  printf("Measured Wind Speed = %lf [m/s]\n", Vw);

  // Calculated Lift force from 
  //   * plane's paramters: CI & Aw
  //   * measured parameters: delta_pressure
  Lift = CI * Aw * delta_pressure;
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
