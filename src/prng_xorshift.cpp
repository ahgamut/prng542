/* Marsaglia's Xorshift Generators. (32bit only)
 * Any one of the below 8 recurrences can be used.
 *
 * y^= y<<a; y^= y>>b; y^= y<<c;
 * y^= y<<c; y^= y>>b; y^= y<<a;
 * y^= y>>a; y^= y<<b; y^= y>>c;
 * y^= y>>c; y^= y<<b; y^= y>>a;
 * y^= y<<a; y^= y<<c; y^= y>>b;
 * y^= y<<c; y^= y<<a; y^= y>>b;
 * y^= y>>a; y^= y>>c; y^= y<<b;
 * y^= y>>c; y^= y>>a; y^= y<<b;
 */
#include "prng_xorshift.h"

static const XorshiftABC Coefficients[] = {
    {1, 3, 10},  {1, 5, 16},   {1, 5, 19},  {1, 9, 29},   {1, 11, 6},
    {1, 11, 16}, {1, 19, 3},   {1, 21, 20}, {1, 27, 27},  {2, 5, 15},
    {2, 5, 21},  {2, 7, 7},    {2, 7, 9},   {2, 7, 25},   {2, 9, 15},
    {2, 15, 17}, {2, 15, 25},  {2, 21, 9},  {3, 1, 14},   {3, 3, 26},
    {3, 3, 28},  {3, 3, 29},   {3, 5, 20},  {3, 5, 22},   {3, 5, 25},
    {3, 7, 29},  {3, 13, 7},   {3, 23, 25}, {3, 25, 24},  {3, 27, 11},
    {4, 3, 17},  {4, 3, 27},   {4, 5, 15},  {5, 3, 21},   {5, 7, 22},
    {5, 9, 7},   {5, 9, 28},   {5, 9, 31},  {5, 13, 6},   {5, 15, 17},
    {5, 17, 13}, {5, 21, 12},  {5, 27, 8},  {5, 27, 21},  {5, 27, 25},
    {5, 27, 28}, {6, 1, 11},   {6, 3, 17},  {6, 17, 9},   {6, 21, 7},
    {6, 21, 13}, {7, 1, 9},    {7, 1, 18},  {7, 1, 25},   {7, 13, 25},
    {7, 17, 21}, {7, 25, 12},  {7, 25, 20}, {8, 7, 23},   {8, 9, 23},
    {9, 5, 1},   {9, 5, 25},   {9, 11, 19}, {9, 21, 16},  {10, 9, 21},
    {10, 9, 25}, {11, 7, 12},  {11, 7, 16}, {11, 17, 13}, {11, 21, 13},
    {12, 9, 23}, {13, 3, 17},  {13, 3, 27}, {13, 5, 19},  {13, 17, 15},
    {14, 1, 15}, {14, 13, 15}, {15, 1, 29}, {17, 15, 20}, {17, 15, 23},
    {17, 15, 26}

};

static u32 XorshiftUpdate1(u32 y, u32 a, u32 b, u32 c) {
    y ^= y << a;
    y ^= y >> b;
    y ^= y << c;
    return y;
}

static u32 XorshiftUpdate2(u32 y, u32 a, u32 b, u32 c) {
    y ^= y << c;
    y ^= y >> b;
    y ^= y << a;
    return y;
}

static u32 XorshiftUpdate3(u32 y, u32 a, u32 b, u32 c) {
    y ^= y >> a;
    y ^= y << b;
    y ^= y >> c;
    return y;
}

static u32 XorshiftUpdate4(u32 y, u32 a, u32 b, u32 c) {
    y ^= y >> c;
    y ^= y << b;
    y ^= y >> a;
    return y;
}

static u32 XorshiftUpdate5(u32 y, u32 a, u32 b, u32 c) {
    y ^= y << a;
    y ^= y << c;
    y ^= y >> b;
    return y;
}

static u32 XorshiftUpdate6(u32 y, u32 a, u32 b, u32 c) {
    y ^= y << c;
    y ^= y << a;
    y ^= y >> b;
    return y;
}

static u32 XorshiftUpdate7(u32 y, u32 a, u32 b, u32 c) {
    y ^= y >> a;
    y ^= y >> c;
    y ^= y << b;
    return y;
}

static u32 XorshiftUpdate8(u32 y, u32 a, u32 b, u32 c) {
    y ^= y >> c;
    y ^= y >> a;
    y ^= y << b;
    return y;
}

static const XorshiftUpdater options[] = {
    XorshiftUpdate8, XorshiftUpdate7, XorshiftUpdate2, XorshiftUpdate6,
    XorshiftUpdate5, XorshiftUpdate4, XorshiftUpdate3, XorshiftUpdate1};

PRNGXorshift::PRNGXorshift(u64 seed, u64 CONSTANT, u64 METHOD) {
    this->abc = Coefficients[CONSTANT % 81];
    this->upfunc = options[METHOD % 8];
    this->limit = 0xffffffffull;
    this->seed = seed % this->limit;
    this->state = this->seed;
    check();
}

void PRNGXorshift::check() {
    if (this->seed == 0)
        std::runtime_error("Invalid PRNG initialization values");
}

void PRNGXorshift::update() {
    this->state = this->upfunc(this->state & this->limit, this->abc.a,
                               this->abc.b, this->abc.c);
}

std::string PRNGXorshift::toString() const {
    std::stringstream ss;
    ss << "PRNGXorshift at (" << this << ") initialized with " << this->seed
       << "\nConstants = {" << this->abc.a << ", " << this->abc.b
       << ", " << this->abc.c << "}"
       << ": (state = " << this->state << ", limit = " << this->limit << ")\n";
    return ss.str();
}

Rcpp::NumericVector PRNGXorshift::unif(u32 n) { return PRNG::unif(n); }
Rcpp::IntegerVector PRNGXorshift::draw(u32 n) { return PRNG::draw(n); }

double PRNGXorshift::get_value() { return PRNG::get_value(); }
