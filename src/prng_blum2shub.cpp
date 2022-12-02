/* The Blum-Blum-Shub Generator.
 * X(n) = (X(n-1) * X(n-1)) % N
 * N = P * Q where both P, Q are primes = 3 modulo 4
 * X(0) must be a quadratic residue modulo N
 */
#include "prng_blum2shub.h"

bool isprime(u64 x) {
    if (x % 2 == 0) return false;
    u64 i = 3, lim = std::sqrt(x);
    for (i = 3; i < lim; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

PRNGBlum2Shub::PRNGBlum2Shub(u64 seed, u64 p, u64 q) {
    this->p = p;
    this->q = q;
    this->limit = p * q;
    this->seed = seed % this->limit;
    this->state = this->seed;
    check();
}

void PRNGBlum2Shub::check() {
    if (this->limit < 2 || this->seed == 0) {
        std::runtime_error("Invalid PRNG initialization values");
    }
    if (this->p % 4 != 3 || this->q % 4 != 3) {
        std::runtime_error("p , q need to be = 3 modulo 4");
    }
    if (!isprime(this->p) || !isprime(this->q)) {
        std::runtime_error("Blum-Blum-Shub needs two primes");
    }
}

void PRNGBlum2Shub::update() {
    this->state = (this->state * this->state) % this->limit;
}

std::string PRNGBlum2Shub::toString() const {
    std::stringstream ss;
    ss << "PRNGBlum2Shub at (" << this << ") initialized with " << this->seed
       << "\np   = " << this->p << ", q = " << this->q
       << ": (state = " << this->state << ", limit = " << this->limit << ")\n";
    return ss.str();
}

Rcpp::NumericVector PRNGBlum2Shub::unif(u32 n) { return PRNG::unif(n); }
Rcpp::IntegerVector PRNGBlum2Shub::draw(u32 n) { return PRNG::draw(n); }

double PRNGBlum2Shub::get_value() { return PRNG::get_value(); }
