\name{prng542-package}
\alias{prng542-package}
\alias{prng542}
\docType{package}
\title{
  A few PRNGs and CDF approximations
}
\description{
  In the STAT 542 lectures, it was mentioned that
    the generation of random numbers would be an interesting exercise,
    although tangentially related to the syllabus of the class. This package
    implements a few simple pseudo-random number generators.
}
\author{
Gautham V

Maintainer: Gautham V <ahgamut@gmail.com>
}
\keyword{ PRNG }
\examples{
  \dontrun{
     prng <- getDefaultPRNG("xorshift")
     draw(prng, n = 20)
     draw_unif(prng, n = 20)
  }
}
