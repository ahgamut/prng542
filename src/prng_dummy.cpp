/*
 * A dummy RNG  -- just goes through values from 0 to N.
 */
#include "prng_dummy.h"

PRNGDummy::PRNGDummy(u64 seed, u64 limit) {
    this->seed = seed % limit;
    this->state = this->seed;
    this->limit = limit;
    this->check();
}

void PRNGDummy::update() { this->state = (this->state + 1) % (this->limit); }

std::string PRNGDummy::toString() const {
    std::stringstream ss;
    ss << "PRNGDummy at (" << this << ")\ninitialized with " << this->seed
       << ": (state = " << this->state << ", limit = " << this->limit << ")\n";
    return ss.str();
}

Rcpp::NumericVector PRNGDummy::unif(u32 n) { return PRNG::unif(n); }
Rcpp::IntegerVector PRNGDummy::draw(u32 n) { return PRNG::draw(n); }

double PRNGDummy::get_value() { return PRNG::get_value(); }
