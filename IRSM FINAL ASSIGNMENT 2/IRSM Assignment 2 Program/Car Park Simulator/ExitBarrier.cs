using System;

namespace Car_Park_Simulator
{
    class ExitBarrier
    {
        private CarPark carPark;
        private string state;

        public ExitBarrier()
        {
        }

        public ExitBarrier(ref CarPark aCarPark)
        {
            state = "LOWERED";
            carPark = aCarPark;
        }

        public void raise()
        {
            state = "RAISED";
        }

        public void lower()
        {
            carPark.increment();
            state = "LOWERED";

        }

        public string getState()
        {
            return state;
        }
    }
}
