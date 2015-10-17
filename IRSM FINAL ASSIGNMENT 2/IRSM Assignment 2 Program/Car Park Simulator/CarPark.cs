using System;

namespace Car_Park_Simulator
{
    class CarPark
    {
        private const int MAX_SPACE = 5;
        private int space = MAX_SPACE;
        private int PaidCoins = 0;

        public CarPark()
        {
            
        }


        public void decrement()
        {
           
            space = (space -1);
            
        }

        public void increment()
        {
            
            space = (space +1);
           
        }

        public int getTotalSpace()
        {
          
            return MAX_SPACE;

        }

        public int getAvailableSpace()
        {
         
             return space;
        }

        public bool isFull()
        {

            if (space == 0 )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        public bool hasAvailableSpaces()
        {

            if (space != MAX_SPACE)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool AreCoinsPaid()
        {
            if (PaidCoins == (MAX_SPACE - space))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public void IncrementPaid()
        {
            PaidCoins = (PaidCoins + 1);
        }

        public void DecrementPaid()
        {
            PaidCoins = (PaidCoins - 1);
        }

        public bool CanCarExit()
        {
            if (PaidCoins > 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

    }

}