using System;
using System.Windows.Forms;
using System.Windows.Input;
using System.Threading;
using System.Speech.Synthesis;
using System.IO;

namespace DetectIfKeyIsPressed {
   public partial class Form1 : Form {
      public Form1() {
         InitializeComponent();
      }

      bool isRunning = true;

      bool customBinds = false;

      bool alreadyExecutedKills = false;
      bool alreadyExecutedDeaths = false;
      bool alreadyExecutedFeedBack = false;
      bool[] alreadyExecutedPauseAplication = {false, false};

      double kills = 0;
      double deaths = 0;
      double kdr = 0;
      double targetKDR = 0;
      double deficitKDR0 = 0;
      double deficitKDR1 = 0;

      string customBindsPath = "\\UserCustomBinds.txt";

      Keys bindConvertKills;
      Key bindKills = Key.Space;

      Keys bindConvertDeaths;
      Key bindDeaths = Key.F;

      Keys bindConvertFeedBack;
      Key BindFeedBack = Key.D4;

      public void Speech(string Speech) {
         
         SpeechSynthesizer speechSynthesizerObj;
         speechSynthesizerObj = new SpeechSynthesizer();
         speechSynthesizerObj.SpeakAsync(Speech);
      }

      public void tts() {
         
         if (deficitKDR1 >= 0) {
            Speech(deficitKDR1.ToString());
         } else {
            System.Media.SoundPlayer player = new System.Media.SoundPlayer("confirm_sound.wav");
            player.Play();
         }
      }

      public void kdrDeficit() {
         
         targetKDR = double.Parse(txtTargetKDR.Text);
         deficitKDR0 = deaths * targetKDR;
         deficitKDR1 = deficitKDR0 - kills;
         lblKdrDefictValue.Text = (deficitKDR1 * -1).ToString("0");
      }

      public void KDR() {
         
         kdr = kills / deaths;
         lblKdrValue.Text = kdr.ToString("0.00");
      }

      public void Kills() {
        
         kills = int.Parse(txtKills.Text);
         kills++;
         txtKills.Text = Convert.ToString(kills);
         kdrDeficit();
         KDR();
         tts();
      }

      public void Deaths() {
         
         deaths = int.Parse(txtDeaths.Text);
         deaths++;
         txtDeaths.Text = Convert.ToString(deaths);
         kdrDeficit();
         KDR();
         tts();
      }

      private void btnReset_Click(object sender, EventArgs e) {
         
         txtDeaths.Text = "0";
         txtKills.Text = "0";
         txtTargetKDR.Text = "0";
         lblKdrValue.Text = "0.00";
         lblKdrDefictValue.Text = "TBA";
         kills = 0;
         deaths = 0;
         kdr = 0;
         targetKDR = 0;
         deficitKDR0 = 0;
         deficitKDR1 = 0;
      }

      private void btnApply_Click(object sender, EventArgs e) {
         
         kills = int.Parse(txtKills.Text);
         deaths = int.Parse(txtDeaths.Text);
         txtKills.Text = Convert.ToString(kills);
         txtDeaths.Text = Convert.ToString(deaths);
         kdrDeficit();
         KDR();
         tts();
      }

      void Keyboardd() {
         while (isRunning) {

            Thread.Sleep(50); //Thread.Sleep(100); Minimum CPU usage

            if (Keyboard.IsKeyDown(bindKills)) {
               
               if (!alreadyExecutedKills) {
                  Kills();
                  alreadyExecutedKills = true;
               }
            } else {
               alreadyExecutedKills = false;
            }

            //-------------------------------------------------------------------------------

            if (Keyboard.IsKeyDown(bindDeaths)) {
               
               if (!alreadyExecutedDeaths) {
                  Deaths();
                  alreadyExecutedDeaths = true;
               }
            } else {
               alreadyExecutedDeaths = false;
            }

            //-------------------------------------------------------------------------------
            
            if (Keyboard.IsKeyDown(BindFeedBack)) {
               
               if (!alreadyExecutedFeedBack) {
               
                  Speech(kills.ToString() + "kills and" + deaths.ToString() + "deaths");
                  alreadyExecutedFeedBack = true;
               }
            } else {
               alreadyExecutedFeedBack = false;
            }

            //-------------------------------------------------------------------------------
            
            if (Keyboard.IsKeyDown(Key.RightAlt)) {
               
               if (!alreadyExecutedPauseAplication[0]) {
                  
                  if (!alreadyExecutedPauseAplication[1]) {
                     
                     bindKills = Key.F13;
                     bindDeaths = Key.F13;
                     BindFeedBack = Key.F13;
                     alreadyExecutedPauseAplication[1] = true;
                     Speech("Paused");
                  } else if (alreadyExecutedPauseAplication[1]) {
                     
                     ReadFile();
                     Speech("Resumed");
                     alreadyExecutedPauseAplication[1] = false;
                  }
                  alreadyExecutedPauseAplication[0] = true; 
               }
            } else {
               alreadyExecutedPauseAplication[0] = false;
            }
         }
      }

        //------------------------------------------------------------------------------------------------------------------

      private void btnKills_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e) {
         
         bindConvertKills = e.KeyData;
         bindKills = KeyInterop.KeyFromVirtualKey((int)bindConvertKills);
         btnKills.Text = "Bind Kills (" + e.KeyData.ToString() + ")";
         lblDummy.Focus();
         customBinds = true;
         BindSaving();
      }

      private void btnKills_Click(object sender, EventArgs e) {
         
         btnKills.Text = "...";
      }

      private void btnKills_Leave(object sender, EventArgs e) {
         
         btnKills.Text = "Bind Kills (" + bindKills.ToString() + ")";
      }

      //------------------------------------------------------------------------------------------------------------------

      private void btnDeaths_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e) {
         
         bindConvertDeaths = e.KeyData;
         bindDeaths = KeyInterop.KeyFromVirtualKey((int)bindConvertDeaths);
         btnDeaths.Text = "Bind Deaths (" + e.KeyData.ToString() + ")";
         lblDummy.Focus();
         customBinds = true;
         BindSaving();
      }

      private void btnDeaths_Click(object sender, EventArgs e) {
         
         btnDeaths.Text = "...";
      }

      private void btnDeaths_Leave(object sender, EventArgs e) {
         
         btnDeaths.Text = "Bind Deaths (" + bindDeaths.ToString() + ")";
      }

      //------------------------------------------------------------------------------------------------------------------

      private void btnFeedBack_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e) {
         
         bindConvertFeedBack = e.KeyData;
         BindFeedBack = KeyInterop.KeyFromVirtualKey((int)bindConvertFeedBack);
         btnFeedBack.Text = "Bind Deaths (" + e.KeyData.ToString() + ")";
         lblDummy.Focus();
         customBinds = true;
         BindSaving();
      }

      private void btnFeedBack_Click(object sender, EventArgs e) {
         
         btnFeedBack.Text = "...";
      }

      private void btnFeedBack_Leave(object sender, EventArgs e) {

         btnFeedBack.Text = "Bind FeedBack (" + BindFeedBack.ToString() + ")";
      }

      //------------------------------------------------------------------------------------------------------------------

      private void ReadFile() {

         StreamReader sr = new StreamReader(Application.StartupPath + customBindsPath);
         KeyConverter k = new KeyConverter();

         if (sr.ReadLine() == null) {
            bindKills = Key.Space;
            bindDeaths = Key.F;
            BindFeedBack = Key.D4;
         } else {
            bindKills = (Key)k.ConvertFromString(sr.ReadLine());
            bindDeaths = (Key)k.ConvertFromString(sr.ReadLine());
            BindFeedBack = (Key)k.ConvertFromString(sr.ReadLine());
         }

         sr.Close();

         btnKills.Text = "Bind Kills (" + bindKills.ToString() + ")";
         btnDeaths.Text = "Bind Deaths (" + bindDeaths.ToString() + ")";
         btnFeedBack.Text = "Bind FeedBack (" + BindFeedBack.ToString() + ")";
      }

      private void Form1_Load(object sender, EventArgs e) {

         Thread TH = new Thread(Keyboardd);
         TH.SetApartmentState(ApartmentState.STA);
         CheckForIllegalCrossThreadCalls = false;
         TH.Start();

         if (File.Exists("UserCustomBinds.txt")) {
            //Console.WriteLine("File Exists, reading from it");
            ReadFile();
         } else {
            //Console.WriteLine("File does not exist, creating one to read from...");
            StreamWriter sw = new StreamWriter(Application.StartupPath + customBindsPath);
            sw.Close();
         }

         ReadFile();
      }

      private void Form1_FormClosed(object sender, FormClosedEventArgs e) {

         isRunning = false;
      }

      private void BindSaving() {
         
         if (customBinds) {
            StreamWriter sw = new StreamWriter(Application.StartupPath + customBindsPath);
            sw.WriteLine();
            sw.WriteLine(bindKills.ToString());
            sw.WriteLine(bindDeaths.ToString());
            sw.WriteLine(BindFeedBack.ToString());
            sw.Close();
         }
      }

      private void btnBinds_Click(object sender, EventArgs e) {

         lblKills.Visible = false;
         lblDeaths.Visible = false;
         lblTargetKdr.Visible = false;
         lblKdrLabel.Visible = false;
         lblKdrValue.Visible = false;
         lblKdrDefictLabel.Visible = false;
         lblKdrDefictValue.Visible = false;

         txtKills.Visible = false;
         txtDeaths.Visible = false;
         txtTargetKDR.Visible = false;

         btnApply.Visible = false;
         btnReset.Visible = false;
         btnBinds.Visible = false;
         btnExit.Visible = true;

         btnKills.Visible = true;
         btnDeaths.Visible = true;
         btnFeedBack.Visible = true;
      }

      private void txtTargetKDR_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e) {

         lblKills.Focus();
      }

      private void btnExit_Click(object sender, EventArgs e) {

         lblKills.Visible = true;
         lblDeaths.Visible = true;
         lblTargetKdr.Visible = true;
         lblKdrLabel.Visible = true;
         lblKdrValue.Visible = true;
         lblKdrDefictLabel.Visible = true;
         lblKdrDefictValue.Visible = true;

         txtKills.Visible = true;
         txtDeaths.Visible = true;
         txtTargetKDR.Visible = true;

         btnApply.Visible = true;
         btnReset.Visible = true;
         btnBinds.Visible = true;
         btnExit.Visible = false;

         btnKills.Visible = false;
         btnDeaths.Visible = false;
         btnFeedBack.Visible = false;

         lblKills.Focus();
      }
   }
}