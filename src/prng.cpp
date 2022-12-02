#include "prng.h"

PRNG::PRNG() {
    this->seed = 1;
    this->state = this->seed;
    this->limit = 2;
}

void PRNG::check() {
    if (this->limit < 2) std::runtime_error("Invalid limit for PRNG");
}

double PRNG::get_value() {
    return this->state / static_cast<double>(this->limit - 1);
}

Rcpp::NumericVector PRNG::unif(u32 n) {
    Rcpp::NumericVector z(n);
    for (u32 i = 0; i < n; ++i) {
        z[i] = this->get_value();
        this->update();
    }
    return z;
}

Rcpp::IntegerVector PRNG::draw(u32 n) {
    Rcpp::IntegerVector z(n);
    for (u32 i = 0; i < n; ++i) {
        z[i] = this->state;
        this->update();
    }
    return z;
}
