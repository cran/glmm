#include "myheader.h"
void elval(double *Y,  int *nrowX, int *ncolX, double *eta, int *family, int *ntrials, double *elval)
{
	double *cumout=Calloc(1,double);
	cumout[0]=0.0;

	/*calling cum3, cp3, cpp3 will just change the doubles cumout, cpout, cppout  */
	cum3(eta,nrowX,family,ntrials, cumout);

	/*calculate value of el: Y^T eta-c(eta)  */
	int intone=1;
	double thing2=0.0, *foo2=&thing2;
	matTvecmult(Y,eta,nrowX,&intone, foo2); /* Y dot eta goes in foo2 */
	elval[0]=foo2[0]-cumout[0];
	Free(cumout);
}


