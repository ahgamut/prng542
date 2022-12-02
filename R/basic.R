loadModule("prng_internals", TRUE)

`_factory` <- list(
    "dummy" = function(seed, limit) {
        prng <- new(`_PRNGDummy`, seed, limit)   
    },
    "middle-square" = function(seed, n) {
        prng <- new(`_PRNGMidsq`, seed, n)   
    },
    "lehmer" = function(seed, limit, k) {
        prng <- new(`_PRNGLehmer`, seed, limit, k)
    },
    "lcg" = function(seed, limit, a, c) {
        prng <- new(`_PRNGLCG`, seed, limit, a, c)
    },
    "blum-blum-shub" = function(seed, p, q) {
        prng <- new(`_PRNGBlum2Shub`, seed, p, q)
    },
    "xorshift" = function(seed, constant, method) {
        prng <- new(`_PRNGXorshift`, seed, constant, method)
    }
)

getPRNG <- function(name, seed, ...) {
    args <- list(...)
    args$seed = seed
    if (name %in% names(`_factory`)) {
        prng <- do.call(`_factory`[[name]], args)
    } else {
        stop("invalid name for RNG")
    }
    prng
}

draw_unif <- function(prng, n = 1) {
    prng$unif(n)
}

draw <- function(prng, n = 1) {
    prng$draw(n)
}