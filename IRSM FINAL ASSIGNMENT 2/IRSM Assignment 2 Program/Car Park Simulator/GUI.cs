using System;
using System.Windows.Forms;

namespace Car_Park_Simulator
{
    public partial class GUI : Form
    {
        private CarPark      carPark;
        private EntryBarrier entryBarrier;
        private ExitBarrier  exitBarrier;
        private FullSign     fullSign;
        private CoinMachine  coinMachine;
   

        public GUI()
        {
            InitializeComponent();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            btnStart.Text = "RESTART";

            carPark = new CarPark();
            entryBarrier = new EntryBarrier(ref carPark);
            exitBarrier = new ExitBarrier(ref carPark);
            fullSign = new FullSign();
            coinMachine = new CoinMachine();

            btnCarArrives.Visible = true;
            btnCarArrivesAtExit.Visible = false;
            btnEnterCarPark.Visible = false;
            btnEnterCoin.Visible = false;
            btnExitCarPark.Visible = false;
            btnPressForCoin.Visible = false;
            btnPaymentforCoin.Visible = false;

            UpdateDisplay();
          
        }

        private void btnCarArrives_Click(object sender, EventArgs e)
        {
            string displayMessage;

            displayMessage = "";
            coinMachine.CarArrives(ref displayMessage);
            txtCoinMachine.Text = displayMessage;

            btnCarArrives.Visible = false;
            btnPressForCoin.Visible = true;
            
            txtCoinMachine.Text = displayMessage;
            UpdateDisplay();
        }

        private void btnPressForCoin_Click(object sender, EventArgs e)
        {

            txtCoinMachine.Text = "";
            coinMachine.decrement();
            entryBarrier.raise();

            btnEnterCoin.Visible = false;
            btnExitCarPark.Visible = false;
            btnEnterCarPark.Visible = true;
            btnPressForCoin.Visible = false;
           
            UpdateDisplay();

        }

        private void btnEnterCarPark_Click(object sender, EventArgs e)
        {
            
            txtCoinMachine.Text = "";
            entryBarrier.lower();

            btnPressForCoin.Visible = false;
            if (carPark.isFull().Equals(true))
            {
                btnCarArrives.Visible = false;
            }
            else
            {
                btnCarArrives.Visible = true;
            }
            
            btnPaymentforCoin.Visible = true;
            btnEnterCarPark.Visible = false;
            string displayMessage;

            displayMessage = "";
            coinMachine.PressPayment(ref displayMessage);
            txtCoinMachine.Text = displayMessage;
            fullSign.ChangeState(ref carPark);
            UpdateDisplay();
        }

        private void btnCarArrivesAtExit_Click(object sender, EventArgs e)
        {
            string displayMessage;

            displayMessage = "";
            coinMachine.CarExits(ref displayMessage);
            txtCoinMachine.Text = displayMessage;

            btnEnterCoin.Visible = true;

            carPark.DecrementPaid();
        
            txtCoinMachine.Text = displayMessage;

            if (carPark.CanCarExit().Equals(true))
            {
                btnCarArrivesAtExit.Visible = false;
            }
            else
            {
                btnCarArrivesAtExit.Visible = true;
            }        

            UpdateDisplay();

        }

        private void btnEnterCoin_Click(object sender, EventArgs e)
        {
            
            txtCoinMachine.Text = "";
            coinMachine.increment();
            exitBarrier.raise();
            
            btnEnterCoin.Visible = false;
            btnExitCarPark.Visible = true;
            UpdateDisplay();
        }

        private void btnExitCarPark_Click(object sender, EventArgs e)
        {
           
            txtCoinMachine.Text = "";
            exitBarrier.lower();
           
            btnCarArrives.Visible = true;
            btnExitCarPark.Visible = false;

            fullSign.ChangeState(ref carPark);
            UpdateDisplay();

        }

        private void btnPaymentforCoin_Click(object sender, EventArgs e)
        {
            //button1_click 
        }

        private void UpdateDisplay()
        {
            txtEntryBarrier.Text = entryBarrier.getState();
            txtExitBarrier.Text = exitBarrier.getState();
            txtFullSign.Text = fullSign.getState().ToString();
            txtAvailableCoins.Text = coinMachine.getNumberOfCoins().ToString();
            txtAvailableSpaces.Text = carPark.getAvailableSpace().ToString();
           
            btnStart.Focus();
        }

        private void txtFullSign_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtCoinMachine_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtAvailableSpaces_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtAvailableCoins_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox5_Enter(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
                carPark.IncrementPaid();
            if (carPark.AreCoinsPaid().Equals(true))
            {
                btnPaymentforCoin.Visible = false;
            }
            else
            {
                btnPaymentforCoin.Visible = true;
            }        
         
           if (carPark.hasAvailableSpaces().Equals(true))
           {
               btnCarArrivesAtExit.Visible = true;
           }
           else
           {
               btnCarArrivesAtExit.Visible = false;
           }

            UpdateDisplay();

        }
    }
}
