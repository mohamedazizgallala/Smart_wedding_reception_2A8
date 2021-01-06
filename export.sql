--------------------------------------------------------
--  File created - Wednesday-January-06-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ANIMATEUR
--------------------------------------------------------

  CREATE TABLE "ANIMATEUR" 
   (	"ID_ANIMATEUR" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"DESCRIPTION" VARCHAR2(20 BYTE), 
	"CONTACTS" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CAR
--------------------------------------------------------

  CREATE TABLE "CAR" 
   (	"MATRICULE" VARCHAR2(20 BYTE), 
	"COULEUR" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER, 
	"MARQUE" VARCHAR2(20 BYTE), 
	"ENTREPRISE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COIFFEURS
--------------------------------------------------------

  CREATE TABLE "COIFFEURS" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"NUMERO" NUMBER, 
	"PRIX" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DECORATEUR
--------------------------------------------------------

  CREATE TABLE "DECORATEUR" 
   (	"ID_DECORATEUR" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"DESCRIPTION" VARCHAR2(20 BYTE), 
	"CONTACTS" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYE
--------------------------------------------------------

  CREATE TABLE "EMPLOYE" 
   (	"ID" VARCHAR2(20 BYTE), 
	"CIN" NUMBER, 
	"PASSWORD" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"CODE" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"ROLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYES
--------------------------------------------------------

  CREATE TABLE "EMPLOYES" 
   (	"ID" NUMBER, 
	"CIN" NUMBER, 
	"PRENOM" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"ROLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EVENEMENT
--------------------------------------------------------

  CREATE TABLE "EVENEMENT" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"DATES" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOCAL
--------------------------------------------------------

  CREATE TABLE "LOCAL" 
   (	"ID" VARCHAR2(20 BYTE), 
	"ENTREPRISE" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER, 
	"ENDROIT" VARCHAR2(20 BYTE), 
	"NB_PERSONNE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOCATEURS
--------------------------------------------------------

  CREATE TABLE "LOCATEURS" 
   (	"NOML" VARCHAR2(20 BYTE), 
	"ADRESSEL" VARCHAR2(20 BYTE), 
	"NUMEROL" NUMBER, 
	"PRIXL" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table OFFRE
--------------------------------------------------------

  CREATE TABLE "OFFRE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"DATEDEBUT" VARCHAR2(20 BYTE), 
	"DATEFIN" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table TRAITEUR
--------------------------------------------------------

  CREATE TABLE "TRAITEUR" 
   (	"ID_TRAITEUR" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"DESCRIPTION" VARCHAR2(20 BYTE), 
	"PRIX" NUMBER, 
	"CONTACTS" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into ANIMATEUR
SET DEFINE OFF;
REM INSERTING into CAR
SET DEFINE OFF;
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('4586TN214','rouge',150,'fiat','luxe');
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('457TN422','bleu',150,'polo','location voiture');
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('dvd452b','bleu',200,'golf','car inc');
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('dgks56s','rouge',556,'fiat','fiat inc');
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('vdkd45s','gris',400,'ford','ford company');
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('vdkd45sk','gris',300,'peugeot','peugeot company');
Insert into CAR (MATRICULE,COULEUR,PRIX,MARQUE,ENTREPRISE) values ('fbfhfd','blanc',520,'polo','location ');
REM INSERTING into COIFFEURS
SET DEFINE OFF;
REM INSERTING into DECORATEUR
SET DEFINE OFF;
REM INSERTING into EMPLOYE
SET DEFINE OFF;
Insert into EMPLOYE (ID,CIN,PASSWORD,PRENOM,CODE,NOM,ROLE) values ('malek',458,'222','malek','fss','labidi','location');
Insert into EMPLOYE (ID,CIN,PASSWORD,PRENOM,CODE,NOM,ROLE) values ('aziz',125,'111','c c','v s','v s','organisation');
Insert into EMPLOYE (ID,CIN,PASSWORD,PRENOM,CODE,NOM,ROLE) values ('zied',562,'333','vd','ds','fe','marketing');
Insert into EMPLOYE (ID,CIN,PASSWORD,PRENOM,CODE,NOM,ROLE) values ('farah',453,'444','dhs','ssh','jgel','beaute');
Insert into EMPLOYE (ID,CIN,PASSWORD,PRENOM,CODE,NOM,ROLE) values ('wissal',459,'555','dgf','hdz','hdz','graphisme');
Insert into EMPLOYE (ID,CIN,PASSWORD,PRENOM,CODE,NOM,ROLE) values ('moslem',486,'666','dms','bez','lpe','RH');
REM INSERTING into EMPLOYES
SET DEFINE OFF;
Insert into EMPLOYES (ID,CIN,PRENOM,NOM,ROLE) values (458,57,'dgh','fjk','Marketing');
REM INSERTING into EVENEMENT
SET DEFINE OFF;
Insert into EVENEMENT (ID,NOM,DATES) values (0,'fdhfdh','gfdg');
REM INSERTING into LOCAL
SET DEFINE OFF;
Insert into LOCAL (ID,ENTREPRISE,TYPE,PRIX,ENDROIT,NB_PERSONNE) values ('dfe5s','manouba location','salle de fete',900,'manouba',500);
REM INSERTING into LOCATEURS
SET DEFINE OFF;
REM INSERTING into OFFRE
SET DEFINE OFF;
Insert into OFFRE (ID,NOM,DATEDEBUT,DATEFIN) values (0,'fhfd','fdgd','gre');
Insert into OFFRE (ID,NOM,DATEDEBUT,DATEFIN) values (4553,'fgj','123','255');
REM INSERTING into TRAITEUR
SET DEFINE OFF;
Insert into TRAITEUR (ID_TRAITEUR,NOM,ADRESSE,DESCRIPTION,PRIX,CONTACTS) values (1111,'vdf','ldf','ldfm',11,'11');
--------------------------------------------------------
--  DDL for Index ANIMATEUR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ANIMATEUR_PK" ON "ANIMATEUR" ("ID_ANIMATEUR") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CAR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "CAR_PK" ON "CAR" ("MATRICULE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DECORATEUR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "DECORATEUR_PK" ON "DECORATEUR" ("ID_DECORATEUR") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "EMPLOYES_PK" ON "EMPLOYES" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "EMPLOYE_PK" ON "EMPLOYE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EVENEMENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "EVENEMENT_PK" ON "EVENEMENT" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index LOCAL_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LOCAL_PK" ON "LOCAL" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index OFFRE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "OFFRE_PK" ON "OFFRE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index TRAITEUR_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TRAITEUR_PK" ON "TRAITEUR" ("ID_TRAITEUR") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ANIMATEUR
--------------------------------------------------------

  ALTER TABLE "ANIMATEUR" ADD CONSTRAINT "ANIMATEUR_PK" PRIMARY KEY ("ID_ANIMATEUR")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "ANIMATEUR" MODIFY ("ID_ANIMATEUR" NOT NULL ENABLE);
  ALTER TABLE "ANIMATEUR" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "ANIMATEUR" MODIFY ("CONTACTS" NOT NULL ENABLE);
  ALTER TABLE "ANIMATEUR" MODIFY ("DESCRIPTION" NOT NULL ENABLE);
  ALTER TABLE "ANIMATEUR" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "ANIMATEUR" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CAR
--------------------------------------------------------

  ALTER TABLE "CAR" ADD CONSTRAINT "CAR_CHK1" CHECK (couleur in ('rouge', 'blanc', 'noir','bleu','rose','vert','jaune','gris')) ENABLE;
  ALTER TABLE "CAR" ADD CONSTRAINT "CAR_PK" PRIMARY KEY ("MATRICULE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "CAR" MODIFY ("ENTREPRISE" NOT NULL ENABLE);
  ALTER TABLE "CAR" MODIFY ("MARQUE" NOT NULL ENABLE);
  ALTER TABLE "CAR" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "CAR" MODIFY ("COULEUR" NOT NULL ENABLE);
  ALTER TABLE "CAR" MODIFY ("MATRICULE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COIFFEURS
--------------------------------------------------------

  ALTER TABLE "COIFFEURS" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "COIFFEURS" MODIFY ("NUMERO" NOT NULL ENABLE);
  ALTER TABLE "COIFFEURS" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "COIFFEURS" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DECORATEUR
--------------------------------------------------------

  ALTER TABLE "DECORATEUR" ADD CONSTRAINT "DECORATEUR_PK" PRIMARY KEY ("ID_DECORATEUR")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "DECORATEUR" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "DECORATEUR" MODIFY ("CONTACTS" NOT NULL ENABLE);
  ALTER TABLE "DECORATEUR" MODIFY ("DESCRIPTION" NOT NULL ENABLE);
  ALTER TABLE "DECORATEUR" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "DECORATEUR" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "DECORATEUR" MODIFY ("ID_DECORATEUR" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYE
--------------------------------------------------------

  ALTER TABLE "EMPLOYE" ADD CONSTRAINT "EMPLOYE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "EMPLOYE" MODIFY ("ROLE" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYE" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYE" MODIFY ("CODE" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYE" MODIFY ("PRENOM" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYE" MODIFY ("PASSWORD" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYE" MODIFY ("CIN" NOT NULL ENABLE);
  ALTER TABLE "EMPLOYE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYES
--------------------------------------------------------

  ALTER TABLE "EMPLOYES" ADD CONSTRAINT "EMPLOYES_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "EMPLOYES" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EVENEMENT
--------------------------------------------------------

  ALTER TABLE "EVENEMENT" ADD CONSTRAINT "EVENEMENT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "EVENEMENT" MODIFY ("ID" NOT NULL ENABLE);
  ALTER TABLE "EVENEMENT" MODIFY ("DATES" NOT NULL ENABLE);
  ALTER TABLE "EVENEMENT" MODIFY ("NOM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LOCAL
--------------------------------------------------------

  ALTER TABLE "LOCAL" MODIFY ("NB_PERSONNE" NOT NULL ENABLE);
  ALTER TABLE "LOCAL" MODIFY ("ENDROIT" NOT NULL ENABLE);
  ALTER TABLE "LOCAL" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "LOCAL" MODIFY ("TYPE" NOT NULL ENABLE);
  ALTER TABLE "LOCAL" MODIFY ("ENTREPRISE" NOT NULL ENABLE);
  ALTER TABLE "LOCAL" ADD CONSTRAINT "LOCAL_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "LOCAL" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LOCATEURS
--------------------------------------------------------

  ALTER TABLE "LOCATEURS" MODIFY ("PRIXL" NOT NULL ENABLE);
  ALTER TABLE "LOCATEURS" MODIFY ("NUMEROL" NOT NULL ENABLE);
  ALTER TABLE "LOCATEURS" MODIFY ("ADRESSEL" NOT NULL ENABLE);
  ALTER TABLE "LOCATEURS" MODIFY ("NOML" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table OFFRE
--------------------------------------------------------

  ALTER TABLE "OFFRE" ADD CONSTRAINT "OFFRE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "OFFRE" MODIFY ("DATEFIN" NOT NULL ENABLE);
  ALTER TABLE "OFFRE" MODIFY ("DATEDEBUT" NOT NULL ENABLE);
  ALTER TABLE "OFFRE" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "OFFRE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table TRAITEUR
--------------------------------------------------------

  ALTER TABLE "TRAITEUR" ADD CONSTRAINT "TRAITEUR_PK" PRIMARY KEY ("ID_TRAITEUR")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TRAITEUR" MODIFY ("CONTACTS" NOT NULL ENABLE);
  ALTER TABLE "TRAITEUR" MODIFY ("PRIX" NOT NULL ENABLE);
  ALTER TABLE "TRAITEUR" MODIFY ("DESCRIPTION" NOT NULL ENABLE);
  ALTER TABLE "TRAITEUR" MODIFY ("ADRESSE" NOT NULL ENABLE);
  ALTER TABLE "TRAITEUR" MODIFY ("NOM" NOT NULL ENABLE);
  ALTER TABLE "TRAITEUR" MODIFY ("ID_TRAITEUR" NOT NULL ENABLE);