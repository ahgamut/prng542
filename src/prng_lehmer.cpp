/* The Lehmer RNG.
 * X(n) = (X(n-1) * k) % m
 */
#include "prng_lehmer.h"

PRNGLehmer::PRNGLehmer(u64 seed, u64 limit, u64 k) {
    this->k = k % limit;
    this->limit = limit;
    this->seed = seed % this->limit;
    this->state = this->seed;
    check();
}

void PRNGLehmer::check() {
    if (this->limit < 2 || this->k == 0 || this->seed == 0)
        std::runtime_error("Invalid PRNG initialization values");
}

void PRNGLehmer::update() { this->state = (this->state * this->k) % this->limit; }

std::string PRNGLehmer::toString() const {
    std::stringstream ss;
    ss << "PRNGLehmer at (" << this << ") initialized with " << this->seed
       << "\nk = " << this->k << ": (state = " << this->state
       << ", limit = " << this->limit << ")\n";
    return ss.str();
}

Rcpp::NumericVector PRNGLehmer::unif(u32 n) { return PRNG::unif(n); }
Rcpp::IntegerVector PRNGLehmer::draw(u32 n) { return PRNG::draw(n); }

double PRNGLehmer::get_value() { return PRNG::get_value(); }
