#include "WaveTableGenerator.h"

#include <math.h>
#include "../../../util/util.h"

void WaveTableGenerator::sine(WaveTable& wavetable, float amplitude, int mult) {
    float* table = wavetable.getTable();
    size_t size = wavetable.getSize();

    for(int i = 0; i < size; i++) {
        float phase = (float(i) / float(size)) * M_PI*2 * mult;
        table[i] += sinf(phase) * amplitude;
    }
}

void WaveTableGenerator::square(WaveTable& wavetable, float pulseWidth, float amplitude, int mult) {
    float* table = wavetable.getTable();
    size_t size = wavetable.getSize();

    for(int i = 0; i < size; i++) {
        float phase = (float(i) / float(size)) * mult;
        int intPhase = static_cast<int>(phase);
        float fracPhase = phase - static_cast<float>(intPhase);

        if(fracPhase < pulseWidth) {
            table[i] += amplitude;
        } else {
            table[i] -= amplitude;
        }
    }
}