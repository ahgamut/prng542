loadModule("prng_internals", TRUE)

._factory <- list(
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
    if (name %in% names(._factory)) {
        prng <- do.call(._factory[[name]], args)
    } else {
        stop("invalid name for RNG")
    }
    prng
}

.nice_factory <- list(
    "dummy" = function() {
        prng <- new(`_PRNGDummy`, 21, 256)   
    },
    "middle-square" = function() {
        prng <- new(`_PRNGMidsq`, 1129, 4)   
    },
    "lehmer" = function() {
        prng <- new(`_PRNGLehmer`, 37, 0x7fffffff, 48271)
    },
    "lcg" = function() {
        prng <- new(`_PRNGLCG`, 55, 0x10001, 75, 74)
    },
    "blum-blum-shub" = function() {
        prng <- new(`_PRNGBlum2Shub`, 3, 11, 23)
    },
    "xorshift" = function() {
        prng <- new(`_PRNGXorshift`, 34, 41, 4)
    }
)

getDefaultPRNG <- function(name) {
    if (name %in% names(.nice_factory)) {
        prng <- .nice_factory[[name]]()
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