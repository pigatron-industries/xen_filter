#ifndef ReverbController_h
#define ReverbController_h

// #include "DaisyDuino.h"
#include "FDNReverb.h"
#include "../../../Controller.h"
#include "../../../io/input/ExpInput.h"
#include "../../../io/input/AnalogInput.h"
#include "../../../io/input/CrossfadeInput.h"
#include "../../../io/input/FilterInput.h"


class ReverbController : public Controller {
    public:
        ReverbController() {}
        virtual void init(float sampleRate);
        virtual void process(float **in, float **out, size_t size);
        virtual void update();

    private:
        ExpInput delayInput = ExpInput(A0, 0.01);
        AnalogInput feedbackInput = AnalogInput(A1, -5, 4.8, 0.0001, 1);
        FilterInput filterInput = FilterInput(A2);

        CrossfadeInput dryWetMix = CrossfadeInput(A4, -4.8, 4.8);
        

        FDNReverb reverb;
        //AllPassFilter allPassFilter;

        int sampleRate;

        void setDelay(float delayTime);
};

#endif
