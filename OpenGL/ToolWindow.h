#include <iostream>

#pragma once

namespace OpenGL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ToolWindow
	/// </summary>
	public ref class ToolWindow : public System::Windows::Forms::Form
	{
	public:
		static bool moveLight, posColor, cubeToSphere, isResetLightClicked, isResetSuzClicked;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::TrackBar^ trackBar4;
	private: System::Windows::Forms::TrackBar^ trackBar5;
	private: System::Windows::Forms::TrackBar^ trackBar6;
	private: System::Windows::Forms::TrackBar^ trackBar7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;

	public:
		ToolWindow(void)
		{
			InitializeComponent();
			moveLight = this->radioButton1->Checked;
			posColor = this->radioButton2->Checked;
			cubeToSphere = this->radioButton3->Checked;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(12, 305);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(93, 20);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Move Light";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(12, 392);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(89, 20);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Transform";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(12, 480);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(106, 20);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Water Scene";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::radioButton3_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 35);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Reset Light Position";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ToolWindow::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 428);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 35);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Reset Transform";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ToolWindow::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Ship Rotation Rate";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(12, 28);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(381, 56);
			this->trackBar1->TabIndex = 6;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar1_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(399, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"0.00";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(399, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 16);
			this->label3->TabIndex = 10;
			this->label3->Text = L"0";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(12, 90);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(381, 56);
			this->trackBar2->TabIndex = 9;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar2_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Specular Strength";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Specular Color";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(35, 152);
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(358, 56);
			this->trackBar3->TabIndex = 12;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar3_Scroll);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 152);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"R";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(399, 152);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 16);
			this->label7->TabIndex = 14;
			this->label7->Text = L"1.00";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(399, 202);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 16);
			this->label8->TabIndex = 17;
			this->label8->Text = L"1.00";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 202);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 16);
			this->label9->TabIndex = 16;
			this->label9->Text = L"G";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(35, 202);
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(358, 56);
			this->trackBar4->TabIndex = 15;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar4_Scroll);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(399, 255);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 16);
			this->label10->TabIndex = 20;
			this->label10->Text = L"1.00";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 255);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(16, 16);
			this->label11->TabIndex = 19;
			this->label11->Text = L"B";
			// 
			// trackBar5
			// 
			this->trackBar5->Location = System::Drawing::Point(35, 255);
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(358, 56);
			this->trackBar5->TabIndex = 18;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar5_Scroll);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(199, 428);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(86, 20);
			this->checkBox1->TabIndex = 21;
			this->checkBox1->Text = L"Translate";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(297, 428);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(69, 20);
			this->checkBox2->TabIndex = 22;
			this->checkBox2->Text = L"Rotate";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(372, 428);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(64, 20);
			this->checkBox3->TabIndex = 23;
			this->checkBox3->Text = L"Scale";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox3_CheckedChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(9, 516);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(71, 16);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Frequency";
			// 
			// trackBar6
			// 
			this->trackBar6->Location = System::Drawing::Point(35, 550);
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(358, 56);
			this->trackBar6->TabIndex = 25;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar6_Scroll);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(399, 550);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(31, 16);
			this->label13->TabIndex = 26;
			this->label13->Text = L"0.00";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(399, 629);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(31, 16);
			this->label14->TabIndex = 29;
			this->label14->Text = L"0.00";
			// 
			// trackBar7
			// 
			this->trackBar7->Location = System::Drawing::Point(35, 629);
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(358, 56);
			this->trackBar7->TabIndex = 28;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar7_Scroll);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(9, 595);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 16);
			this->label15->TabIndex = 27;
			this->label15->Text = L"Amplitude";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(12, 725);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(110, 20);
			this->radioButton4->TabIndex = 30;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Space Scene";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::radioButton4_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(12, 681);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(139, 20);
			this->checkBox4->TabIndex = 31;
			this->checkBox4->Text = L"Wireframe Render";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(199, 681);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(81, 20);
			this->checkBox5->TabIndex = 32;
			this->checkBox5->Text = L"Tint Blue";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBox5_CheckedChanged);
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 761);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->trackBar6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		moveLight = ((RadioButton^)sender)->Checked;
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		posColor = ((RadioButton^)sender)->Checked;
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		cubeToSphere = ((RadioButton^)sender)->Checked;
	}
	private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		isResetLightClicked = true;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		isResetSuzClicked = true;
	}
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar5_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar6_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trackBar7_Scroll(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
