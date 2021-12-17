
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

static const uint64_t uint_64_val_2 = static_cast<uint64_t>(2);
static const uint32_t mr_det_32_hash_mult = 0xAD625B89;

static const uint32_t mr_det_32_hash_table[] = {
    1216, 1836, 8885, 4564, 10978, 5228, 15613, 13941,
	1553, 173, 3615, 3144, 10065, 9259, 233, 2362,
	6244, 6431, 10863, 5920, 6408, 6841, 22124, 2290,
	45597, 6935, 4835, 7652, 1051, 445, 5807, 842,
	1534, 22140, 1282, 1733, 347, 6311, 14081, 11157,
	186, 703, 9862, 15490, 1720, 17816, 10433, 49185,
	2535, 9158, 2143, 2840, 664, 29074, 24924, 1035,
	41482, 1065, 10189, 8417, 130, 4551, 5159, 48886,
	786, 1938, 1013, 2139, 7171, 2143, 16873, 188,
	5555, 42007, 1045, 3891, 2853, 23642, 148, 3585,
	3027, 280, 3101, 9918, 6452, 2716, 855, 990,
	1925, 13557, 1063, 6916, 4965, 4380, 587, 3214,
	1808, 1036, 6356, 8191, 6783, 14424, 6929, 1002,
	840, 422, 44215, 7753, 5799, 3415, 231, 2013,
	8895, 2081, 883, 3855, 5577, 876, 3574, 1925,
	1192, 865, 7376, 12254, 5952, 2516, 20463, 186,
	5411, 35353, 50898, 1084, 2127, 4305, 115, 7821,
	1265, 16169, 1705, 1857, 24938, 220, 3650, 1057,
	482, 1690, 2718, 4309, 7496, 1515, 7972, 3763,
	10954, 2817, 3430, 1423, 714, 6734, 328, 2581,
	2580, 10047, 2797, 155, 5951, 3817, 54850, 2173,
	1318, 246, 1807, 2958, 2697, 337, 4871, 2439,
	736, 37112, 1226, 527, 7531, 5418, 7242, 2421,
	16135, 7015, 8432, 2605, 5638, 5161, 11515, 14949,
	748, 5003, 9048, 4679, 1915, 7652, 9657, 660,
	3054, 15469, 2910, 775, 14106, 1749, 136, 2673,
	61814, 5633, 1244, 2567, 4989, 1637, 1273, 11423,
	7974, 7509, 6061, 531, 6608, 1088, 1627, 160,
	6416, 11350, 921, 306, 18117, 1238, 463, 1722,
	996, 3866, 6576, 6055, 130, 24080, 7331, 3922,
	8632, 2706, 24108, 32374, 4237, 15302, 287, 2296,
	1220, 20922, 3350, 2089, 562, 11745, 163, 11951
};

// This gcd function is specialized for the library (not for general use)
uint32_t gcd(uint32_t a, uint32_t b) {
	uint32_t temp;
	while(b) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// This pow_mod function is specialized for the library (not for general use)
uint64_t pow_int_mod(uint64_t base, uint32_t exponent, uint64_t mod) {
    if(base >= mod) {
        base %= mod;
    }
    uint64_t result = 1;
    while(exponent) {
        if(exponent & 1) {
            result = (result * base) % mod;
            exponent -= 1;
        } else {
            base = (base * base) % mod;
            exponent >>= 1;
        }
    }
    return result;
}

bool miller_rabin_det_32_bit(uint32_t num) {
    if(num < 4) {
        if(num < 2) {
            return false;
        }
        return true;
    }
    if(!(num & 1)) {
        return false;
    }
    bool loop_check = true;
    uint32_t d = num >> 1;
    int32_t r = 1;
    while(!(d & 1)) {
        d >>= 1;
        r++;
    }
    uint64_t num_cast = num;
    uint64_t max_residue = num_cast - 1;
    uint64_t x = pow_int_mod(uint_64_val_2, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
                break;
            }
        }
        if(loop_check) {
            return false;
        }
    }
    uint32_t hash_val = (num * mr_det_32_hash_mult) >> 24;
    uint32_t base = mr_det_32_hash_table[hash_val];
    if(gcd(num, base) != 1) {
        return false;
    }
    x = pow_int_mod(base, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        loop_check = true;
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
                break;
            }
        }
        if(loop_check) {
            return false;
        }
    }
    return true;
}
