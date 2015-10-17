using System;

namespace Car_Park_Simulator
{
    class CoinMachine
    {

       private int noOfCoins = 5;
        

        public CoinMachine()
        {          
            
        }

        public void decrement()
        {
            
            noOfCoins = (noOfCoins - 1);

        }

        public void increment()
        {
          
            noOfCoins = (noOfCoins +1);
        }

        public int getNumberOfCoins()
           {
                return noOfCoins;
            }

        public void EnterCoin()
        {
            increment();
     
        }

        public void CarArrives(ref string machineDisplay)
        {
           
            machineDisplay = "Please Press for Coin";
         
        }

        public void CarExits(ref string machineDisplay)
        {
            
            machineDisplay = "Please Enter Coin";

        }

        public void PressCoin()
        {
          
            decrement();

        }

        public void PressPayment(ref string machineDisplay)
        {
            machineDisplay = "Please Pay for your Stay";

        }
    }
}
