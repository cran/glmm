\name{BoothHobert}
\docType{data}
\alias{BoothHobert}
\concept{generalized linear mixed model}
\title{A Logit-Normal GLMM Dataset from Booth and Hobert}
\description{This data set contains simulated data from the paper of Booth and Hobert referenced below. }

\usage{data(BoothHobert)}
\format{
  A data frame with 3 columns:

   \describe{
    \item{y}{Response vector.}
    \item{x1}{Fixed effect model matrix. The matrix has just one column vector.}
    \item{z1}{Random effect model matrix. The matrix has just one column vector.}
  }
}
\details{This data set was generated by Booth and Hobert using a single variance component, a single fixed effect, no intercept, and a logit link.}

\references{Booth, J. G. and Hobert, J. P. (1999)  Maximizing generalized linear mixed model likelihoods with an automated Monte Carlo EM algorithm. \emph{Journal of the Royal Statistical Society, Series B}, \bold{61}, 265--285. \doi{10.1111/1467-9868.00176}.}
\examples{
data(BoothHobert)
}
\keyword{datasets}

