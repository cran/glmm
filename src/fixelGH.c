#include "myheader.h"
void fixelGH(double *Y, double *X, int *nrowX, int *ncolX, double *eta, int *family, double *elgradient, double *elhessian)
{
	double *cpout=Calloc(*nrowX,double);
	double *cppout=Calloc(*nrowX,double);

	/*calling cp3, cpp3 will just change the doubles cpout, cppout  */

	cp3(eta,nrowX,family,cpout);
	cpp3(eta,nrowX,family,cppout);

	/*calculate gradient of el: X^T (Y-c'(eta))  
	first use loop to calculate Y-c'(eta). then turn c''(eta) into -c''(eta)*/
	double *Yminuscp=Calloc(*nrowX,double);
	int i=0;
	for(i=0;i<(*nrowX);i++)
		{
		Yminuscp[i]=Y[i]-cpout[i];
		cppout[i]=-cppout[i];
		}
	Free(cpout);
	/*invoking matTvecmult clobbers dummy values of elgradient with actual values*/
	matTvecmult(X,Yminuscp,nrowX,ncolX,elgradient);
	Free(Yminuscp);

	/*  need to create diagonal matrix negcdub=-c''(eta) from vector cppout  */
	int sizemat=(*nrowX)*(*nrowX);
	double *negcdub=Calloc(sizemat,double);
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
	matTmatmult(X,mat,nrowX,ncolX,ncolX,elhessian);
	Free(mat);
}

