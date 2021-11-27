#pragma once
#include "Services.h"
#include <iostream>
#include <string>
#include "Personne.h"

namespace P6new {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgv_enr;
	protected:

	private: System::Windows::Forms::Button^ btn_load;
	private: System::Windows::Forms::Button^ btn_insert;
	private: System::Windows::Forms::Button^ btn_delete;
	private: System::Windows::Forms::Button^ btn_update;

	private: System::Windows::Forms::TextBox^ txt_code_client;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::TextBox^ txt_prenom;
	private: System::Windows::Forms::TextBox^ txt_date_naissance;




	private: NS_Comp_Svc::CLservices^ oSvc;

	private: System::Data::DataSet^ oDs;
	protected:

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
				Personne^ p = (Personne^) list[i];
				//DataRow^ dr= dt->Rows->Add(p->id, p->nom, p->prenom);
				DataGridViewRow^ row = gcnew DataGridViewRow();
				row->CreateCells(this->dgv_enr, p->codeClient, p->nom, p->prenom, p->dateNaissance, p->numService, p->activiteClient);
				row->Tag = p;
				this->dgv_enr->Rows->Add(row);
			}
			//this->dgv_enr->DataSource = dt;
			//this->dgv_enr->Refresh();
			/*
			this->oDs = this->oSvc->selectionnerToutesLesPersonnes("Rsl");
			this->dgv_enr->DataSource = this->oDs;
			this->dgv_enr->DataMember = "Rsl";
			this->dgv_enr->Refresh();
			DataRow^ row = this->oDs->Tables["Rsl"]->Rows->Add(2222, "test");
			this->dgv_enr->Rows[this->dgv_enr->Rows->Count-1]->Tag = gcnew String("toto");
			*/
			
		}
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgv_enr = (gcnew System::Windows::Forms::DataGridView());
			this->btn_load = (gcnew System::Windows::Forms::Button());
			this->btn_insert = (gcnew System::Windows::Forms::Button());
			this->btn_delete = (gcnew System::Windows::Forms::Button());
			this->btn_update = (gcnew System::Windows::Forms::Button());
			this->txt_code_client = (gcnew System::Windows::Forms::TextBox());
			this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			this->txt_date_naissance = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_enr
			// 
			this->dgv_enr->AllowUserToAddRows = false;
			this->dgv_enr->AllowUserToDeleteRows = false;
			this->dgv_enr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_enr->Location = System::Drawing::Point(12, 12);
			this->dgv_enr->Name = L"dgv_enr";
			this->dgv_enr->ReadOnly = true;
			this->dgv_enr->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_enr->Size = System::Drawing::Size(472, 150);
			this->dgv_enr->TabIndex = 0;
			this->dgv_enr->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dgv_enr_CellClick);
			// 
			// btn_load
			// 
			this->btn_load->Location = System::Drawing::Point(15, 183);
			this->btn_load->Name = L"btn_load";
			this->btn_load->Size = System::Drawing::Size(75, 129);
			this->btn_load->TabIndex = 1;
			this->btn_load->Text = L"Load DB";
			this->btn_load->UseVisualStyleBackColor = true;
			this->btn_load->Click += gcnew System::EventHandler(this, &MyForm::btn_load_Click);
			// 
			// btn_insert
			// 
			this->btn_insert->Location = System::Drawing::Point(96, 183);
			this->btn_insert->Name = L"btn_insert";
			this->btn_insert->Size = System::Drawing::Size(75, 37);
			this->btn_insert->TabIndex = 2;
			this->btn_insert->Text = L"INS";
			this->btn_insert->UseVisualStyleBackColor = true;
			this->btn_insert->Click += gcnew System::EventHandler(this, &MyForm::btn_insert_Click);
			// 
			// btn_delete
			// 
			this->btn_delete->Enabled = false;
			this->btn_delete->Location = System::Drawing::Point(96, 275);
			this->btn_delete->Name = L"btn_delete";
			this->btn_delete->Size = System::Drawing::Size(75, 37);
			this->btn_delete->TabIndex = 3;
			this->btn_delete->Text = L"DEL";
			this->btn_delete->UseVisualStyleBackColor = true;
			this->btn_delete->Click += gcnew System::EventHandler(this, &MyForm::btn_delete_Click);
			// 
			// btn_update
			// 
			this->btn_update->Location = System::Drawing::Point(96, 229);
			this->btn_update->Name = L"btn_update";
			this->btn_update->Size = System::Drawing::Size(75, 37);
			this->btn_update->TabIndex = 4;
			this->btn_update->Text = L"UPD";
			this->btn_update->UseVisualStyleBackColor = true;
			this->btn_update->Click += gcnew System::EventHandler(this, &MyForm::btn_update_Click);
			// 
			// txt_code_client
			// 
			this->txt_code_client->Location = System::Drawing::Point(204, 168);
			this->txt_code_client->Name = L"txt_code_client";
			this->txt_code_client->Size = System::Drawing::Size(172, 20);
			this->txt_code_client->TabIndex = 5;
			// 
			// txt_nom
			// 
			this->txt_nom->Location = System::Drawing::Point(203, 194);
			this->txt_nom->Name = L"txt_nom";
			this->txt_nom->Size = System::Drawing::Size(172, 20);
			this->txt_nom->TabIndex = 6;
			// 
			// txt_prenom
			// 
			this->txt_prenom->Location = System::Drawing::Point(203, 220);
			this->txt_prenom->Name = L"txt_prenom";
			this->txt_prenom->Size = System::Drawing::Size(172, 20);
			this->txt_prenom->TabIndex = 7;
			// 
			// txt_date_naissance
			// 
			this->txt_date_naissance->Location = System::Drawing::Point(204, 246);
			this->txt_date_naissance->Name = L"txt_date_naissance";
			this->txt_date_naissance->Size = System::Drawing::Size(171, 20);
			this->txt_date_naissance->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 329);
			this->Controls->Add(this->txt_date_naissance);
			this->Controls->Add(this->txt_prenom);
			this->Controls->Add(this->txt_nom);
			this->Controls->Add(this->txt_code_client);
			this->Controls->Add(this->btn_update);
			this->Controls->Add(this->btn_delete);
			this->Controls->Add(this->btn_insert);
			this->Controls->Add(this->btn_load);
			this->Controls->Add(this->dgv_enr);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_enr))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_load_Click(System::Object^ sender, System::EventArgs^ e)
	{
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
		Personne^ p = (Personne^) this->dgv_enr->CurrentRow->Tag;
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