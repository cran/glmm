
#ifndef GLMM_MYHEADER_H
#define GLMM_MYHEADER_H

#define BERNOULLI 1
#define POISSON 2

#include <R.h>
#include <R_ext/BLAS.h>

void cum3(double *etain, int *neta, int *typein, double *cumout);
void cp3(double *etain, int *neta, int *typein, double *cpout);
void cpp3(double *etain, int *neta, int *typein, double *cppout);

void matTvecmult(double *a, double *b, int *nrow, int *ncol, double *result);
void diag(double *invec, int *nrow, double *outmat);
void matTmatmult(double *a, double *b, int *nrowa, int *ncola, int *ncolb,
    double *c);
void matmatmult(double *a, double *b, int *nrowa, int *ncola, int *ncolb,
    double *c);
void matvecmult(double *a, double *b, int *nrow, int *ncol, double *result);
void identmat(int *nrow, int *diagmat);
void sumup(double *a, int *lena, double *suma);
void subvec(double *a, double *b, int *len, double *out);
void addvec(double *a, double *b, int *len, double *out);
void divvec(double *a, double *b, int *len, double *out);
void distRandGenC(double *SigmaInv, double *logdet, int *nrow, double *uvec, double *mu, double *distRandGenVal);
void elval(double *Y,  int *nrowX, int *ncolX, double *eta, int *family, double *elval);

void distRand3C(double *nu, double *mu, int *T, int *nrandom, int *meow, double *Uvec, double *drgradient, double *drhessian);

void elGH(double *Y, double *X, int *nrowX, int *ncolX, double *eta, int *family, double *elgradient, double *elhessian);

void objfunc(double *y, double *Umat, int *myq, int *m, double *x, int *n, int *nbeta, double *beta, double *z, double *Dinvfornu, double *logdetDinvfornu, int *family_glmm, double *Dstarinv, double *logdetDstarinv, double *ustar, double *Sigmuhinv, double *logdetSigmuhinv, double *pee, int *nps, int *T, int *nrandom, int *meow, double *nu, int *zeta, double *tconst, double *v, double *value, double *gradient, double *hessian);

void tdist(double *DstarInv,  int *myq, double *uvec, int *zeta, double *tconst, double *logft);

#include <math.h>

#endif /* GLMM_MYHEADER_H */

