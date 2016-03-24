/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

Program.cs - C# wrapper which utilizes a DLL to run the C++ source code of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee             3/10/16         created initial GUI and added start/end buttons
                                to faciliate execution of the program
Lee             3/14/16         created a status bar and added four labels to indicate
                                the success/failure of each verification component
Lee             3/23/16         added code to update the four status bar labels based
                                on the success/failure of the verification process
--------------------------------------------------------------------------------
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace wrapper
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }

        /// <summary>
        /// startButton_Click() executes each time the start button on the GUI is clicked, it serves to allow the user to continue verifying orders
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void startButton_Click(object sender, EventArgs e)
        {
            var instance = new Answer();
            instance.continue_verification = true;
            this.Close();
           // instance.driver();
        }

        /// <summary>
        /// endButton_Click() executes each time the end button on the GUI is clicked, it is used to terminate the software
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void endButton_Click(object sender, EventArgs e)
        {
            var instance = new Answer();
            instance.terminateVerificationSoftware();
            this.Close();
        }
        
        /// <summary>
        /// statusLabel_Click() is required as an event handler for the labels on the status bar, but currently serves no purpose
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void statusLabel_Click(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// profileStatus_Success() indicates the success of the profile verification process by changing the color of the profile status label to green
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void profileStatus_Success(object sender, EventArgs e) // Profile
        {
            profileStatus.BackColor = Color.Green;
            Console.WriteLine("Profile Verification Succeeded");
        }

        /// <summary>
        /// profileStatus_Failure() indicates the failure of the profile verification process by changing the color of the profile status label to red
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void profileStatus_Failure(object sender, EventArgs e) // Profile
        {
            profileStatus.BackColor = Color.Red;
            Console.WriteLine("Profile Verification Failed");
        }

        /// <summary>
        /// lengthStatus_Success() indicates the success of the length verification process by changing the color of the length status label to green
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void lengthStatus_Success(object sender, EventArgs e) 
        {
            lengthStatus.BackColor = Color.Green;
            Console.WriteLine("Length Verification Succeeded");
        }

        /// <summary>
        /// lengthStatus_Failure() indicates the failure of the length verification process by changing the color of the length status label to red
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void lengthStatus_Failure(object sender, EventArgs e) 
        {
            lengthStatus.BackColor = Color.Red;
            Console.WriteLine("Length Verification Failed");
        }

        /// <summary>
        /// colorStatus_Success() indicates the success of the colo verification process by changing the color of the color status label to green
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void colorStatus_Success(object sender, EventArgs e) 
        {
            colorStatus.BackColor = Color.Green;
            Console.WriteLine("Color Verification Succeeded");
        }

        /// <summary>
        /// colorStatus_Failure() indicates the failure of the color verification process by changing the color of the color status label to red
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void colorStatus_Failure(object sender, EventArgs e)
        {
            colorStatus.BackColor = Color.Red;
            Console.WriteLine("Color Verification Failed");
        }

        /// <summary>
        /// quantityStatus_Success() indicates the success of the quantity verification process by changing the color of the quantity status label to green
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void quantityStatus_Success(object sender, EventArgs e)
        {
            quantityStatus.BackColor = Color.Green;
            Console.WriteLine("Quantity Verification Succeeded");
        }

        /// <summary>
        /// quantityStatus_Failure() indicates the failure of the quantity verification process by changing the color of the quantity status label to red
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void quantityStatus_Failure(object sender, EventArgs e)
        {
            quantityStatus.BackColor = Color.Red;
            Console.WriteLine("Quantity Verification Failed");
        }

    }
}
