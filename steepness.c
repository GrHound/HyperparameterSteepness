/*

Very often in machine learning, one needs to control a hyperparameter value such as the learning rate over the epochs. A specific example would consist of an exponential decay of a learning rate eta over the epochs. However, the optimal shape of such a controlling curve is not known. Either a fast decay, linear decay or even a slow-start decay are needed. Similar to the gamma parameter in image-intensity adjustment, a single parameter, here alpha, can control the convexity of the hyperparameter curve over epochs. We have used the trick in training of Kohohen maps and in controlling the leniency of a reward schedule in reinforcement learning (see below).

L. Schomaker (2004).

Used in:

Schomaker & Bulacu (2004), Eq. 8. Schomaker, L & Bulacu, M 2004, 'Automatic writer identification using connected-component contours and edge-based features of uppercase western script', IEEE transactions on pattern analysis and machine intelligence, vol. 26, no. 6, pp. 787-798.

and

Luo, Kasaei & Schomaker (2020).
Accelerating Reinforcement Learning for Reaching Using Continuous Curriculum Learning, ISBN={9781728169262}, url={http://dx.doi.org/10.1109/IJCNN48605.2020.9207427}, DOI={10.1109/ijcnn48605.2020.9207427,IEEE - International Joint Conference on Neural Networks (IJCNN).

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double tolerance_curve(double steepness, 
                double rmin, double rmax, int istep, int nsteps)
{
   double o,r,c,crmax,crmin;

   c = (double) steepness;
        
   crmax = pow ( (double) rmax-rmin, (double) 1./c);
   crmin = pow ( (double) 0.0, (double) 1./c);
   
   r = crmax + (double) istep * (crmin-crmax)/(double)(nsteps-1);
   o = rmin + pow(r,c);
   return( (double) o);
}

int main(int argc, char *argv[])
{
   double tol_start,tol_end,alpha;
   int i,nsteps;
   
   if(argc != 5) {
      fprintf(stderr,"Usage: steepness tol_start tol_end alpha nsteps\n");
      exit(1);
   }
   tol_start = atof(argv[2]);
   tol_end = atof(argv[1]);
   alpha = atof(argv[3]);
   nsteps = atoi(argv[4]);
   
   for(i = 0; i < nsteps; ++i) {
/*      fprintf(stderr,"Step: %d Tolerance: %f\n", i, tolerance_curve(alpha,tol_start,tol_end,i,nsteps)); */
      printf("%d %f\n", i, tolerance_curve(alpha,tol_start,tol_end,i,nsteps));
   }
}
