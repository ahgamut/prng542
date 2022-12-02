/*
 * John Von Neumann's 'middle-square' RNG
 * we have N only as 2 or 4
 */
#include "prng_midsq.h"

PRNGMidsq::PRNGMidsq(u64 seed, u64 n) {
    if (n == 2) {
        this->limit = 100;
    } else if (n == 4) {
        this->limit = 10000;
    } else {
        this->limit = 1;
    }
    this->seed = seed % this->limit;
    this->state = this->seed;
    check();
}

void PRNGMidsq::check() {
    if (this->limit < 2)
        throw std::runtime_error("Invalid value of n, use only 2 or 4");
}

void PRNGMidsq::update() {
    u64 sq = this->state * this->state;
    u64 lim = sqrt(this->limit);
    sq /= lim;
    sq %= this->limit;
    this->state = sq;
}

std::string PRNGMidsq::toString() const {
    std::stringstream ss;
    ss << "PRNGMidsq at (" << this << ")\ninitialized with " << this->seed
       << ": (state = " << this->state << ", limit = " << this->limit << ")\n";
    return ss.str();
}

Rcpp::NumericVector PRNGMidsq::unif(u32 n) { return PRNG::unif(n); }
Rcpp::IntegerVector PRNGMidsq::draw(u32 n) { return PRNG::draw(n); }

double PRNGMidsq::get_value() { return PRNG::get_value(); }
