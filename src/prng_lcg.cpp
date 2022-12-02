/* Linear Congruential Generators
 * X(n) = (a * X(n-1) + c) % m
 * */
#include "prng_lcg.h"

PRNGLCG::PRNGLCG(u64 seed, u64 limit, u64 a, u64 c) {
    this->a = a;
    this->c = c;
    this->limit = limit;
    this->seed = seed % this->limit;
    this->state = this->seed;
    check();
}

void PRNGLCG::check() {
    if (this->limit < 2 || this->a == 0 || this->c == 0)
        throw std::runtime_error("Invalid PRNG initialization values");
}

void PRNGLCG::update() {
    this->state = ((this->a * this->state) + this->c) % this->limit;
}

std::string PRNGLCG::toString() const {
    std::stringstream ss;
    ss << "PRNGLCG at (" << this << ")\ninitialized with " << this->seed
       << "\na = " << this->a << ", c = " << this->c
       << ": (state = " << this->state << ", limit = " << this->limit << ")\n";
    return ss.str();
}

Rcpp::NumericVector PRNGLCG::unif(u32 n) { return PRNG::unif(n); }
Rcpp::IntegerVector PRNGLCG::draw(u32 n) { return PRNG::draw(n); }

double PRNGLCG::get_value() { return PRNG::get_value(); }
