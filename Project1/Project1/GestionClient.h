#pragma once
#include "ServicesClient.h"
#include <iostream>
#include <string>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de GestionClient
	/// </summary>
	public ref class GestionClient : public System::Windows::Forms::Form
	{
	public:
		GestionClient(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~GestionClient()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridView^ dgv_enr;
	protected:
	private: System::Windows::Forms::Button^ btn_retour;
	private: System::Windows::Forms::Button^ btn_insert;
	private: System::Windows::Forms::Button^ btn_delete;
	private: System::Windows::Forms::Button^ btn_update;

	private: System::Windows::Forms::TextBox^ txt_code_client;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::TextBox^ txt_prenom;
	private: System::Windows::Forms::TextBox^ txt_date_naissance;

	private: NS_Comp_Svc::CLservices^ oSvc;
	private: System::Data::DataSet^ oDs;

	private:
		void reloadDataClient() {
			ArrayList^ list = this->oSvc->select();
			this->dgv_enr->Columns->Clear();
			this->dgv_enr->Columns->Add("code client", "code client");
			this->dgv_enr->Columns->Add("nom", "nom");
			this->dgv_enr->Columns->Add("prenom", "prenom");
			this->dgv_enr->Columns->Add("date naissance", "date naissance");
			this->dgv_enr->Columns->Add("num service", "num service");
			this->dgv_enr->Columns->Add("activite client", "activite client");
			this->dgv_enr->Rows->Clear();
			for (int i = 0;i < list->Count;i++) {
				Personne^ p = (Personne^)list[i];
				DataGridViewRow^ row = gcnew DataGridViewRow();
				row->CreateCells(this->dgv_enr, p->codeClient, p->nom, p->prenom, p->dateNaissance, p->numService, p->activiteClient);
				row->Tag = p;
				this->dgv_enr->Rows->Add(row);
			}
		}
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GestionClient::typeid));
			this->dgv_enr = (gcnew System::Windows::Forms::DataGridView());
			this->btn_insert = (gcnew System::Windows::Forms::Button());
			this->btn_delete = (gcnew System::Windows::Forms::Button());
			this->btn_update = (gcnew System::Windows::Forms::Button());
			this->txt_code_client = (gcnew System::Windows::Forms::TextBox());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->txt_date_naissance = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_retour = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_enr
			// 
			this->dgv_enr->AllowUserToAddRows = false;
			this->dgv_enr->AllowUserToDeleteRows = false;
			this->dgv_enr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_enr->Location = System::Drawing::Point(99, 89);
			this->dgv_enr->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgv_enr->Name = L"dgv_enr";
			this->dgv_enr->ReadOnly = true;
			this->dgv_enr->RowHeadersWidth = 51;
			this->dgv_enr->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_enr->Size = System::Drawing::Size(629, 185);
			this->dgv_enr->TabIndex = 0;
			this->dgv_enr->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GestionClient::dgv_enr_CellClick);
			// 
			// btn_insert
			// 
			this->btn_insert->Location = System::Drawing::Point(141, 375);
			this->btn_insert->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_insert->Name = L"btn_insert";
			this->btn_insert->Size = System::Drawing::Size(100, 46);
			this->btn_insert->TabIndex = 2;
			this->btn_insert->Text = L"INS";
			this->btn_insert->UseVisualStyleBackColor = true;
			this->btn_insert->Click += gcnew System::EventHandler(this, &GestionClient::btn_insert_Click);
			// 
			// btn_delete
			// 
			this->btn_delete->Enabled = false;
			this->btn_delete->Location = System::Drawing::Point(141, 488);
			this->btn_delete->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_delete->Name = L"btn_delete";
			this->btn_delete->Size = System::Drawing::Size(100, 46);
			this->btn_delete->TabIndex = 3;
			this->btn_delete->Text = L"DEL";
			this->btn_delete->UseVisualStyleBackColor = true;
			this->btn_delete->Click += gcnew System::EventHandler(this, &GestionClient::btn_delete_Click);
			// 
			// btn_update
			// 
			this->btn_update->Location = System::Drawing::Point(141, 431);
			this->btn_update->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_update->Name = L"btn_update";
			this->btn_update->Size = System::Drawing::Size(100, 46);
			this->btn_update->TabIndex = 4;
			this->btn_update->Text = L"UPD";
			this->btn_update->UseVisualStyleBackColor = true;
			this->btn_update->Click += gcnew System::EventHandler(this, &GestionClient::btn_update_Click);
			// 
			// txt_code_client
			// 
			this->txt_code_client->Location = System::Drawing::Point(283, 375);
			this->txt_code_client->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_code_client->Name = L"txt_code_client";
			this->txt_code_client->Size = System::Drawing::Size(228, 22);
			this->txt_code_client->TabIndex = 5;
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(283, 420);
			this->txt_nom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(228, 22);
			this->txt_nom->TabIndex = 6;
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(283, 467);
			this->txt_prenom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(228, 22);
			this->txt_prenom->TabIndex = 7;
			// 
			// txt_date_naissance
			// 
			this->txt_date_naissance->Location = System::Drawing::Point(283, 512);
			this->txt_date_naissance->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txt_date_naissance->Name = L"txt_date_naissance";
			this->txt_date_naissance->Size = System::Drawing::Size(228, 22);
			this->txt_date_naissance->TabIndex = 8;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(540, 329);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(245, 258);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// btn_retour
			// 
			this->btn_retour->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->btn_retour->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_retour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_retour->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_retour->Location = System::Drawing::Point(16, 15);
			this->btn_retour->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_retour->Name = L"btn_retour";
			this->btn_retour->Size = System::Drawing::Size(116, 34);
			this->btn_retour->TabIndex = 10;
			this->btn_retour->Text = L"<<";
			this->btn_retour->UseVisualStyleBackColor = false;
			this->btn_retour->Click += gcnew System::EventHandler(this, &GestionClient::btn_retour_Click);
			// 
			// GestionClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ClientSize = System::Drawing::Size(800, 601);
			this->Controls->Add(this->txt_date_naissance);
			this->Controls->Add(this->txt_prenom);
			this->Controls->Add(this->txt_nom);
			this->Controls->Add(this->txt_code_client);
			this->Controls->Add(this->btn_update);
			this->Controls->Add(this->btn_delete);
			this->Controls->Add(this->btn_insert);
			this->Controls->Add(this->dgv_enr);
			this->Controls->Add(this->btn_retour);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"GestionClient";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GestionClient";
			this->Load += gcnew System::EventHandler(this, &GestionClient::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_retour_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->oSvc = gcnew NS_Comp_Svc::CLservices();
		this->reloadDataClient();
	}
	private: System::Void btn_insert_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->oSvc->ajouterUnClient(this->txt_nom->Text, this->txt_prenom->Text, System::Convert::ToDateTime(this->txt_date_naissance->Text));
		this->reloadDataClient();
	}
	private: System::Void btn_delete_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void dgv_enr_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (this->dgv_enr->CurrentRow->IsNewRow)
			return;
		Personne^ p = (Personne^)this->dgv_enr->CurrentRow->Tag;
		this->txt_code_client->Text = System::Convert::ToString(p->codeClient);
		this->txt_nom->Text = p->nom;
		this->txt_prenom->Text = p->prenom;

		//this->txt_id->Text = gcnew String(std::to_string((int)this->dgv_enr->CurrentRow->Cells[0]->Value).c_str());
		//this->txt_id->Text = (String^) this->dgv_enr->CurrentRow->Tag;
		this->btn_delete->Enabled = true;
	}

private: System::Void btn_update_Click(System::Object^ sender, System::EventArgs^ e) {
	Personne^ p = (Personne^)this->dgv_enr->CurrentRow->Tag;
	p->nom = this->txt_nom->Text;
	p->prenom = this->txt_prenom->Text;
	this->oSvc->update(p);
	this->reloadDataClient();
}
};
}
