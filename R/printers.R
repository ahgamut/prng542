loadModule("prng_internals", TRUE)

defprinter <- function(prng) {
    cat(prng$toString())
}

setMethod("show", "Rcpp__PRNGDummy", defprinter)
setMethod("show", "Rcpp__PRNGMidsq", defprinter)
setMethod("show", "Rcpp__PRNGLehmer", defprinter)
setMethod("show", "Rcpp__PRNGLCG", defprinter)
setMethod("show", "Rcpp__PRNGBlum2Shub", defprinter)
setMethod("show", "Rcpp__PRNGXorshift", defprinter)