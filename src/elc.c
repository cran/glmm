#include "myheader.h"
void elc(double *Y, double *X, int *nrowX, int *ncolX, double *eta, int *family,  int *ntrials, double *elval, double *elgradient, double *elhessian)
{

	double cumout=0.0;
	double *cpout=Calloc(*nrowX, double);
	memset(cpout,0,*nrowX);
	double *cppout=Calloc(*nrowX, double);
	memset(cppout,0,*nrowX);

	/*calling cum3, cp3, cpp3 will just change the doubles cumout, cpout, cppout  */
	cum3(eta, nrowX, family, ntrials, &cumout);
	cp3(eta, nrowX, family, ntrials, cpout);
	cpp3(eta, nrowX, family, ntrials, cppout);


	/*calculate value of el: Y^T eta-c(eta)  */
	int thing1=1,*ione=&thing1;
	double thing2=0.0, *foo2=&thing2;
	matTvecmult(Y,eta,nrowX,ione, foo2); /* Y dot eta goes in foo2 */
	elval[0]=foo2[0]-cumout;

	/*calculate gradient of el: X^T (Y-c'(eta))  
	first use loop to calculate Y-c'(eta) and turn c''(eta) into -c''(eta)*/
	double *Yminuscp=Calloc(*nrowX,double);
	int i=0;
	for(i=0;i<(*nrowX);i++)
		{
		*(Yminuscp+i)=*(Y+i)-*(cpout+i);
		*(cppout+i)=-*(cppout+i);
		}
	Free(cpout);
	/*invoking matTvecmult clobbers dummy values of elgradient with actual values*/
	matTvecmult(X,Yminuscp,nrowX,ncolX,elgradient);
	Free(Yminuscp);

	/*  need to create diagonal matrix negcdub=-c''(eta) from vector cppout  */
	int sizemat=(*nrowX)*(*nrowX);
	double *negcdub=Calloc(sizemat,double);
	memset(negcdub,0,sizemat);
	diag(cppout, nrowX, negcdub); 
	Free(cppout);

	/*calculate hessian of el: X^T (-c''(eta)) X  
	first start with (-c''(eta))X
 	(nxn)x(nxp)=nxp=nrowX x ncolX*/
	double *mat=Calloc((*nrowX)*(*ncolX),double);
	matmatmult(negcdub,X,nrowX,nrowX,ncolX,mat);
	Free(negcdub);

	/*then calculate X^T mat    
	this multiplication will clobber elhessian with the correct value*/
	elhessian[0]=1.0;
	matTmatmult(X,mat,nrowX,ncolX,ncolX,elhessian);
	Free(mat);
}


