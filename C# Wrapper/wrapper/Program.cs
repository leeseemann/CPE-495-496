/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

Program.cs - C# wrapper which utilizes a DLL to run the C++ source code of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee 			12/28/15		file created, imported C++ DLL


--------------------------------------------------------------------------------
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace wrapper
{
    static class Program
    {
        [STAThread]
        [DllImport("A:\\School\\Spring 2016\\CPE 496\\Code\\CPE_Senior_Design\\DLL\\Debug\\Steelcase_Answer_Verification_DLL.dll")]
        public static extern void Steelcase_Answer_Verification();

        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            Steelcase_Answer_Verification();
        }
    }
}
