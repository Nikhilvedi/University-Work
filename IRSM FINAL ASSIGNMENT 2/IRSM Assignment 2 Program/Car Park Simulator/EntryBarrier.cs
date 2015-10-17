using System;

namespace Car_Park_Simulator
{
    class EntryBarrier
    {
        private CarPark carPark;
        private string state;

        public EntryBarrier()
        {
        }

        public EntryBarrier(ref CarPark aCarPark)
        {
            carPark = aCarPark;
            state = "LOWERED";
        }
        
        public void raise()
        {
            state = "RAISED";
        }

        public void lower()
        {
            state = "LOWERED";
            carPark.decrement();
        }

        public string getState()
        {
            return state;
        }
    }
}
