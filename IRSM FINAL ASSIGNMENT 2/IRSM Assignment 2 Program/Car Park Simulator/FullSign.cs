using System;

namespace Car_Park_Simulator

{
    class FullSign
    {
        private bool state;
       
        public FullSign()
        {

        }

         public bool getState()
        {
       
            return state;
        }
       
        
        public void ChangeState( ref CarPark aCarPark)
        {

            if (aCarPark.isFull() == true )
            {
                this.state = true;
            }

            else 
            {
                this.state = false;
            }
        }
        
        
        
       


    }
}
