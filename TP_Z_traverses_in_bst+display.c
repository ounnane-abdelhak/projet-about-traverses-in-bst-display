

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>


#define MAXHEI 1000
#define INFI (1<<20)

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))




  typedef int bool ;

  #define True 1
  #define False 0

  /** Implementation **\: PILE DE ENTIERS**/
  /** Piles **/

  typedef int Typeelem_Pi ;
  typedef struct Maillon_Pi * Pointeur_Pi ;
  typedef   Pointeur_Pi  Typepile_Pi  ;

  struct Maillon_Pi
    {
      Typeelem_Pi  Val ;
      Pointeur_Pi Suiv ;
    } ;

  void Creerpile_Pi( Pointeur_Pi *P )
    { *P = NULL ; }

  bool Pilevide_Pi ( Pointeur_Pi P )
    { return  (P == NULL ); }

  void Empiler_Pi ( Pointeur_Pi *P,  Typeelem_Pi Val )
    {
      Pointeur_Pi Q;

      Q = (struct Maillon_Pi *) malloc( sizeof( struct Maillon_Pi))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_Pi ( Pointeur_Pi *P,  Typeelem_Pi *Val )
    {
      Pointeur_Pi Sauv;

      if (! Pilevide_Pi (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implementation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tib Type_Tib  ;
  typedef Type_Tib * Typestr_Tib ;
  typedef int Type1_Tib  ;
  typedef bool Type2_Tib  ;
  struct Tib
    {
      Type1_Tib Champ1 ;
      Type2_Tib Champ2 ;
    };

  Type1_Tib Struct1_Tib ( Typestr_Tib S)
    {
      return  S->Champ1 ;
    }

  Type2_Tib Struct2_Tib ( Typestr_Tib S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tib ( Typestr_Tib S, Type1_Tib Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tib ( Typestr_Tib S, Type2_Tib Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tib Typeelem_ATib   ;
  typedef struct Noeud_ATib * Pointeur_ATib ;

  struct Noeud_ATib
    {
      Typeelem_ATib  Val ;
      Pointeur_ATib Fg ;
      Pointeur_ATib Fd ;
      Pointeur_ATib Pere ;
     } ;

  Typeelem_ATib Info_ATib( Pointeur_ATib P )
    { return P->Val;   }

  Pointeur_ATib Fg_ATib( Pointeur_ATib P)
    { return P->Fg ; }

  Pointeur_ATib Fd_ATib( Pointeur_ATib P)
    { return P->Fd ; }

  Pointeur_ATib Pere_ATib( Pointeur_ATib P)
    { return P->Pere ; }

  void Aff_info_ATib ( Pointeur_ATib P, Typeelem_ATib Val)
    {
      Typeelem_ATib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATib( Pointeur_ATib *P)
    {
      *P = (struct Noeud_ATib *) malloc( sizeof( struct Noeud_ATib))   ;
      (*P)->Val = malloc(sizeof(Type_Tib));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATib( Pointeur_ATib P)
    { free( P ) ; }


  /** Implementation **\: LISTE DE STRUCTURES**/

  /** Listes lineaires chainees **/

  typedef Typestr_Tib Typeelem_LTib   ;
  typedef struct Maillon_LTib * Pointeur_LTib ;

  struct Maillon_LTib
    {
      Typeelem_LTib  Val ;
      Pointeur_LTib Suiv ;
    } ;

  Pointeur_LTib Allouer_LTib (Pointeur_LTib *P)
    {
      *P = (struct Maillon_LTib *) malloc( sizeof( struct Maillon_LTib)) ;
      (*P)->Val = malloc(sizeof(Type_Tib));
      (*P)->Suiv = NULL;
    }

  void Aff_val_LTib(Pointeur_LTib P, Typeelem_LTib Val)
    {
      Typeelem_LTib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
      P->Val = Val ;
    }

  void Aff_adr_LTib( Pointeur_LTib P,  Pointeur_LTib Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_LTib Suivant_LTib(  Pointeur_LTib P)
    { return( P->Suiv ) ;  }

  Typeelem_LTib Valeur_LTib( Pointeur_LTib P)
    { return( P->Val) ; }

  void Liberer_LTib ( Pointeur_LTib P)
    { free (P);}


  /** Implementation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATib Typeelem_PATib ;
  typedef struct Maillon_PATib * Pointeur_PATib ;
  typedef   Pointeur_PATib  Typepile_PATib  ;

  struct Maillon_PATib
    {
      Typeelem_PATib  Val ;
      Pointeur_PATib Suiv ;
    } ;

  void Creerpile_PATib( Pointeur_PATib *P )
    { *P = NULL ; }

  bool Pilevide_PATib ( Pointeur_PATib P )
    { return  (P == NULL ); }

  void Empiler_PATib ( Pointeur_PATib *P,  Typeelem_PATib Val )
    {
      Pointeur_PATib Q;

      Q = (struct Maillon_PATib *) malloc( sizeof( struct Maillon_PATib))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATib ( Pointeur_PATib *P,  Typeelem_PATib *Val )
    {
      Pointeur_PATib Sauv;

      if (! Pilevide_PATib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implementation **\: PILE DE STRUCTURES**/
  /** Piles **/

  typedef Typestr_Tib Typeelem_PTib ;
  typedef struct Maillon_PTib * Pointeur_PTib ;
  typedef   Pointeur_PTib  Typepile_PTib  ;

  struct Maillon_PTib
    {
      Typeelem_PTib  Val ;
      Pointeur_PTib Suiv ;
    } ;

  void Creerpile_PTib( Pointeur_PTib *P )
    { *P = NULL ; }

  bool Pilevide_PTib ( Pointeur_PTib P )
    { return  (P == NULL ); }

  void Empiler_PTib ( Pointeur_PTib *P,  Typeelem_PTib Val )
    {
      Pointeur_PTib Q;

      Q = (struct Maillon_PTib *) malloc( sizeof( struct Maillon_PTib))   ;
      Q->Val = malloc(sizeof(Type_Tib));
      Typeelem_PTib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PTib ( Pointeur_PTib *P,  Typeelem_PTib *Val )
    {
      Pointeur_PTib Sauv;

      if (! Pilevide_PTib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }

   
  /** Variables du programme principal **/
  Pointeur_Pi P1=NULL;
  Pointeur_Pi P2=NULL;
  Pointeur_ATib L=NULL;
  Pointeur_ATib L1=NULL;
  Pointeur_LTib Lis1=NULL;
  Typestr_Tib R;
  int H;
  int C;
  bool Continue;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Initialisation d'une structure **/
  void Init_struct_Tib ( Typestr_Tib S, Type_Tib S_ )
    {
      S->Champ1 = S_.Champ1 ;
      S->Champ2 = S_.Champ2 ;
    }


  /** Prototypes des fonctions **/

  void Take_stk_3 (Pointeur_ATib *T , Pointeur_Pi *P , Pointeur_Pi *Ph);
  void Travers_3 (Pointeur_ATib *T , Pointeur_Pi *P);
  void Take_stk_1 (Pointeur_ATib *T , Pointeur_Pi *P , Pointeur_Pi *Ph);
  void Travers_1 (Pointeur_ATib *T , Pointeur_Pi *P);
  void Create_trees (Pointeur_ATib *T , Pointeur_ATib *T1);
  bool  Verify_1 (Pointeur_Pi *P , Pointeur_ATib *R) ;
  bool  Verify_3 (Pointeur_Pi *P , Pointeur_ATib *R) ;
  void Liberer_arbre (Pointeur_ATib *R);
  void Initialize_tree (Pointeur_ATib *R);
  void Viderpile (Pointeur_Pi *P);
  void Inorder (Pointeur_ATib *R , Pointeur_Pi *P);
  bool  Verifie_arb (Pointeur_ATib *R) ;
  void Travers_2 (Pointeur_ATib *R , Pointeur_Pi *P);
  void Take_leafs_2 (Pointeur_ATib *R , Pointeur_Pi *P);
  void Travers_4 (Pointeur_ATib *R , Pointeur_Pi *P);
  void Take_leafs_4 (Pointeur_ATib *R , Pointeur_Pi *P);
  bool  Verify_2 (Pointeur_ATib *R , Pointeur_Pi *P) ;
  void Delete_leafs_2 (Pointeur_ATib *R , Pointeur_Pi *P2);
  bool  Verify_4 (Pointeur_ATib *R , Pointeur_Pi *P) ;
  void Delete_leafs_4 (Pointeur_ATib *R , Pointeur_Pi *P2);

  /* procedure travers 3--------------------------------------------------------------------*/
  void Take_stk_3 (Pointeur_ATib *T , Pointeur_Pi *P , Pointeur_Pi *Ph)
    {
      /** Variables locales **/
      Typestr_Tib S;
      int Mem;
      Type_Tib S_S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *T != NULL)   {
      /* Affectation globale de structure */
       S->Champ1 =   Info_ATib ( *T )->Champ1;
       S->Champ2 =   Info_ATib ( *T )->Champ2;
 ;
       S_S.Champ1 = Struct1_Tib(S) ;
       S_S.Champ2 = True ;
       Init_struct_Tib ( S , S_S )  ;
       Aff_info_ATib ( *T , S ) ;
       Empiler_Pi (& *P , Struct1_Tib ( S  ) ) ;
       if( Fd_ATib ( *T ) == NULL)   {
         if( Fg_ATib ( *T ) == NULL)   {
           while( Pilevide_Pi ( *P ) == False)  {
             Depiler_Pi (& *P , &Mem ) ;
             Empiler_Pi (& *Ph , Mem ) ;
            
           }
         }
       } ;
       _Px1 =  Fd_ATib ( *T ) ;
       Take_stk_3 ( &_Px1, & *P , & *Ph ) ;
       _Px2 =  Fg_ATib ( *T ) ;
       Take_stk_3 ( &_Px2, & *P , & *Ph ) ;
      
     }
    }
  /*----------------------------------------------------------*/
  void Travers_3 (Pointeur_ATib *T , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Pointeur_Pi Ph=NULL;
      int M;

      /** Corps du module **/
     Creerpile_Pi (& Ph ) ;
     Take_stk_3 ( & *T , & *P , & Ph ) ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &M ) ;
       Empiler_Pi (& *P , M ) ;
      
     }
    }
  /* procedure travers 1---------------------------------------------------------------------------------*/
  void Take_stk_1 (Pointeur_ATib *T , Pointeur_Pi *P , Pointeur_Pi *Ph)
    {
      /** Variables locales **/
      Typestr_Tib S;
      int Mem;
      Type_Tib S_S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *T != NULL)   {
      /* Affectation globale de structure */
       S->Champ1 =   Info_ATib ( *T )->Champ1;
       S->Champ2 =   Info_ATib ( *T )->Champ2;
 ;
       S_S.Champ1 = Struct1_Tib(S) ;
       S_S.Champ2 = True ;
       Init_struct_Tib ( S , S_S )  ;
       Aff_info_ATib ( *T , S ) ;
       Empiler_Pi (& *P , Struct1_Tib ( S  ) ) ;
       if( Fd_ATib ( *T ) == NULL)   {
         if( Fg_ATib ( *T ) == NULL)   {
           while( Pilevide_Pi ( *P ) == False)  {
             Depiler_Pi (& *P , &Mem ) ;
             Empiler_Pi (& *Ph , Mem ) ;
            
           } ;
          
         }
       } ;
       _Px1 =  Fg_ATib ( *T ) ;
       Take_stk_1 ( &_Px1, & *P , & *Ph ) ;
       _Px2 =  Fd_ATib ( *T ) ;
       Take_stk_1 ( &_Px2, & *P , & *Ph ) ;
      
     }
    }
  /*----------------------------------------------------------------------------------*/
  void Travers_1 (Pointeur_ATib *T , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Pointeur_Pi Ph=NULL;
      int M;

      /** Corps du module **/
     Creerpile_Pi (& Ph ) ;
     Take_stk_1 ( & *T , & *P , & Ph ) ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &M ) ;
       Empiler_Pi (& *P , M ) ;
      
     }
    }
  /*---------------------------------------------------------------------------------------------*/
  void Create_trees (Pointeur_ATib *T , Pointeur_ATib *T1)
    {
      /** Variables locales **/
      Pointeur_ATib N=NULL;
      Pointeur_ATib N1=NULL;
      Pointeur_ATib K=NULL;
      Pointeur_ATib K1=NULL;
      int Bcl2;
      int M1;
      int M2;
      int Bcl1;
      Typestr_Tib R;
      Type_Tib S_R;

      /** Corps du module **/
     R = malloc(sizeof(Type_Tib));
     Creernoeud_ATib (& *T ) ;
     S_R.Champ1 = Aleanombre(50)+39 ;
     S_R.Champ2 = False ;
     Init_struct_Tib ( R , S_R )  ;
     Aff_info_ATib ( *T , R ) ;
     Creernoeud_ATib (& *T1 ) ;
     Aff_info_ATib ( *T1 , R ) ;
     for( Bcl2  =  1 ;Bcl2 <=  99 ; ++Bcl2){
       Creernoeud_ATib (& K ) ;
       S_R.Champ1 = Aleanombre(100) ;
       S_R.Champ2 = False ;
       Init_struct_Tib ( R , S_R )  ;
       Aff_info_ATib ( K , R ) ;
       Creernoeud_ATib (& K1 ) ;
       Aff_info_ATib ( K1 , R ) ;
       M2  =  Struct1_Tib ( Info_ATib ( K )  ) ;
       N  =  *T ;
       N1  =  *T1 ;
       Continue  =  False ;
       while( Continue == False)  {
      /* Affectation globale de structure */
         R->Champ1 =   Info_ATib ( N )->Champ1;
         R->Champ2 =   Info_ATib ( N )->Champ2;
 ;
         M1  =  Struct1_Tib ( R  ) ;
         if( M1 > M2)   {
           if( Fg_ATib ( N ) == NULL)   {
             Aff_fg_ATib ( N , K ) ;
             Aff_fg_ATib ( N1 , K1 ) ;
             Aff_pere_ATib ( K1 , N1 ) ;
             Aff_pere_ATib ( K , N ) ;
             Continue  =  True ;
             }
           else
             {
             N  =  Fg_ATib ( N ) ;
             N1  =  Fg_ATib ( N1 ) ;
            
           } ;
          
         } ;
         if( M1 < M2)   {
           if( Fd_ATib ( N ) == NULL)   {
             Aff_fd_ATib ( N , K ) ;
             Aff_fd_ATib ( N1 , K1 ) ;
             Aff_pere_ATib ( K1 , N1 ) ;
             Aff_pere_ATib ( K , N ) ;
             Continue  =  True ;
             }
           else
             {
             N  =  Fd_ATib ( N ) ;
             N1  =  Fd_ATib ( N1 ) ;
            
           } ;
          
         } ;
         if( M1 == M2)   {
           Liberernoeud_ATib ( K ) ;
           Liberernoeud_ATib ( K1 ) ;
           Continue  =  True ;
           Bcl2  =  Bcl2 - 1 ;
          
         } ;
        
       } ;
      
     } ;
    
    }
  /*--------------------------------------------------------------------------*/
  bool  Verify_1 (Pointeur_Pi *P , Pointeur_ATib *R) 
    {
      /** Variables locales **/
      bool  Verify_12 ;
      Pointeur_LTib Li1=NULL;
      Pointeur_LTib Li2=NULL;
      Pointeur_LTib Li3=NULL;
      Pointeur_ATib E=NULL;
      Pointeur_PATib Pp1=NULL;
      Pointeur_PTib Pp2=NULL;
      Pointeur_Pi Ph=NULL;
      Typestr_Tib Inf;
      int Num;

      /** Corps du module **/
     Inf = malloc(sizeof(Type_Tib));
     if( *R != NULL) {
       Creerpile_PATib (& Pp1 ) ;
       Creerpile_PTib (& Pp2 ) ;
       Creerpile_Pi (& Ph ) ;
       E  =  *R ;
       Empiler_PATib (& Pp1 , E ) ;
       while( Pilevide_PATib ( Pp1 ) == False)  {
         Depiler_PATib (& Pp1 , &E ) ;
         Empiler_PTib (& Pp2 , Info_ATib ( E ) ) ;
         if( ( Fd_ATib ( E ) == NULL ) && ( Fg_ATib ( E ) == NULL ))   {
           while( Pilevide_PTib ( Pp2 ) == False)  {
             Depiler_PTib (& Pp2 , &Inf ) ;
             Allouer_LTib (& Li3 ) ;
             Aff_val_LTib ( Li3 , Inf ) ;
             if( Li2 == NULL)   {
               Li2  =  Li3 ;
               }
             else
               {
               Aff_adr_LTib ( Li2 , Li3 ) ;
               Li2  =  Li3 ;
              
             } ;
             if( Li1 == NULL)   {
               Li1  =  Li3 ;
              
             } ;
            
           } ;
           }
         else
           {
           if( Fd_ATib ( E ) != NULL)   {
             Empiler_PATib (& Pp1 , Fd_ATib ( E ) ) ;
            
           } ;
           if( Fg_ATib ( E ) != NULL)   {
             Empiler_PATib (& Pp1 , Fg_ATib ( E ) ) ;
            
           } ;
          
         } ;
        
       } ;
      
     } ;
     Verify_12  =  True ;
     while( Li1 != NULL)  {
       if( Pilevide_Pi ( *P ) == True)   {
         Verify_12  =  False ;
         }
       else
         {
         Depiler_Pi (& *P , &Num ) ;
      /* Affectation globale de structure */
         Inf->Champ1 =   Valeur_LTib ( Li1 )->Champ1;
         Inf->Champ2 =   Valeur_LTib ( Li1 )->Champ2;
 ;
         if( ( Num != Struct1_Tib ( Inf  ) ) || ( Struct2_Tib ( Inf  ) == False ))   {
           Verify_12  =  False ;
          
         } ;
        
       } ;
       Empiler_Pi (& Ph , Num ) ;
       Li2  =  Suivant_LTib ( Li1 ) ;
       Liberer_LTib ( Li1 ) ;
       Li1  =  Li2 ;
      
     } ;
     if( Pilevide_Pi ( *P ) == False)   {
       Verify_12  =  False ;
      
     } ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &Num ) ;
       Empiler_Pi (& *P , Num ) ;
      
     } ;
     Li1  =  NULL ;
     Li2  =  NULL ;
     Li3  =  NULL ;
    
     return Verify_12 ;
    }
  /*--------------------------------------------------------------------------*/
  bool  Verify_3 (Pointeur_Pi *P , Pointeur_ATib *R) 
    {
      /** Variables locales **/
      bool  Verify_32 ;
      Pointeur_LTib Li1=NULL;
      Pointeur_LTib Li2=NULL;
      Pointeur_LTib Li3=NULL;
      Pointeur_ATib E=NULL;
      Pointeur_PATib Pp1=NULL;
      Pointeur_PTib Pp2=NULL;
      Pointeur_Pi Ph=NULL;
      Typestr_Tib Inf;
      int Num;

      /** Corps du module **/
     Inf = malloc(sizeof(Type_Tib));
     if( *R != NULL) {
       Creerpile_PATib (& Pp1 ) ;
       Creerpile_PTib (& Pp2 ) ;
       Creerpile_Pi (& Ph ) ;
       E  =  *R ;
       Empiler_PATib (& Pp1 , E ) ;
       while( Pilevide_PATib ( Pp1 ) == False)  {
         Depiler_PATib (& Pp1 , &E ) ;
         Empiler_PTib (& Pp2 , Info_ATib ( E ) ) ;
         if( ( Fd_ATib ( E ) == NULL ) && ( Fg_ATib ( E ) == NULL ))   {
           while( Pilevide_PTib ( Pp2 ) == False)  {
             Depiler_PTib (& Pp2 , &Inf ) ;
             Allouer_LTib (& Li3 ) ;
             Aff_val_LTib ( Li3 , Inf ) ;
             if( Li2 == NULL)   {
               Li2  =  Li3 ;
               }
             else
               {
               Aff_adr_LTib ( Li2 , Li3 ) ;
               Li2  =  Li3 ;
              
             } ;
             if( Li1 == NULL)   {
               Li1  =  Li3 ;
              
             } ;
            
           } ;
           }
         else
           {
           if( Fg_ATib ( E ) != NULL)   {
             Empiler_PATib (& Pp1 , Fg_ATib ( E ) ) ;
            
           } ;
           if( Fd_ATib ( E ) != NULL)   {
             Empiler_PATib (& Pp1 , Fd_ATib ( E ) ) ;
            
           } ;
          
         } ;
        
       } ;
      
     } ;
     Verify_32  =  True ;
     while( Li1 != NULL)  {
       if( Pilevide_Pi ( *P ) == True)   {
         Verify_32  =  False ;
         }
       else
         {
         Depiler_Pi (& *P , &Num ) ;
      /* Affectation globale de structure */
         Inf->Champ1 =   Valeur_LTib ( Li1 )->Champ1;
         Inf->Champ2 =   Valeur_LTib ( Li1 )->Champ2;
 ;
         if( ( Num != Struct1_Tib ( Inf  ) ) || ( Struct2_Tib ( Inf  ) == False ))   {
           Verify_32  =  False ;
          
         } ;
        
       } ;
       Empiler_Pi (& Ph , Num ) ;
       Li2  =  Suivant_LTib ( Li1 ) ;
       Liberer_LTib ( Li1 ) ;
       Li1  =  Li2 ;
      
     } ;
     if( Pilevide_Pi ( *P ) == False)   {
       Verify_32  =  False ;
      
     } ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &Num ) ;
       Empiler_Pi (& *P , Num ) ;
      
     } ;
     Li1  =  NULL ;
     Li2  =  NULL ;
     Li3  =  NULL ;
    
     return Verify_32 ;
    }
  /*-------------------------------------------------------------------*/
  void Liberer_arbre (Pointeur_ATib *R)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fg_ATib ( *R ) ;
       Liberer_arbre ( &_Px1) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Liberer_arbre ( &_Px2) ;
       Liberernoeud_ATib ( *R ) ;
      
     } ;
    
    }
  /*-----------------------------------------------------------------------*/
  void Initialize_tree (Pointeur_ATib *R)
    {
      /** Variables locales **/
      Typestr_Tib N;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;
      Type_Tib S_N;

      /** Corps du module **/
     N = malloc(sizeof(Type_Tib));
     if( *R != NULL) {
       _Px1 =  Fg_ATib ( *R ) ;
       Initialize_tree ( &_Px1) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Initialize_tree ( &_Px2) ;
       S_N.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
       S_N.Champ2 = False ;
       Init_struct_Tib ( N , S_N )  ;
       Aff_info_ATib ( *R , N ) ;
      
     } ;
    
    }
  /*------------------------------------------------------------------------*/
  void Viderpile (Pointeur_Pi *P)
    {
      /** Variables locales **/
      int N;

      /** Corps du module **/
     while( Pilevide_Pi ( *P ) == False)  {
       Depiler_Pi (& *P , &N ) ;
      
     } ;
    
    }
  /*----------------------------------------------------------------------*/
  void Inorder (Pointeur_ATib *R , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL)   {
       _Px1 =  Fg_ATib ( *R ) ;
       Inorder ( &_Px1, & *P ) ;
       Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Inorder ( &_Px2, & *P ) ;
      
     } ;
    
    }
  /*----------------------------------------------------------------------*/
  bool  Verifie_arb (Pointeur_ATib *R) 
    {
      /** Variables locales **/
      bool  Verifie_arb2 ;
      Pointeur_Pi P=NULL;
      int N1;
      int N2;

      /** Corps du module **/
     Inorder ( & *R , & P ) ;
     Verifie_arb2  =  True ;
     if( Pilevide_Pi ( P ) == False)   {
       Depiler_Pi (& P , &N1 ) ;
       while( Pilevide_Pi ( P ) == False)  {
         Depiler_Pi (& P , &N2 ) ;
         if( N2 >= N1)   {
           Verifie_arb2  =  False ;
          
         } ;
         N1  =  N2 ;
        
       } ;
      
     } ;
    
     return Verifie_arb2 ;
    }
  /*---------------------------------------------------------------*/
  void Travers_2 (Pointeur_ATib *R , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Pointeur_Pi P2=NULL;

      /** Corps du module **/
     Creerpile_Pi (& P2 ) ;
     while( ( ( Fg_ATib ( *R ) != NULL ) || ( Fd_ATib ( *R ) != NULL ) ) && ( ( Fg_ATib ( *R ) != NULL ) || ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) != True ) ) && ( ( Fd_ATib ( *R ) != NULL ) || ( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) != True ) ) && ( ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) != True ) || ( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) != True ) ))  {
       Take_leafs_2 ( & *R , & *P ) ;
      
     } ;
     Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
     while( Pilevide_Pi ( *P ) == False)  {
       Depiler_Pi (& *P , &H ) ;
       Empiler_Pi (& P2 , H ) ;
      
     } ;
     *P  =  P2 ;
    
    }
  /*-----------------------------------------------------*/
  void Take_leafs_2 (Pointeur_ATib *R , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Typestr_Tib M;
      Type_Tib S_M;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     M = malloc(sizeof(Type_Tib));
     if( ( *R != NULL ))   {
       if( ( Struct2_Tib ( Info_ATib ( *R )  ) == False ))   {
         if( ( Fg_ATib ( *R ) == NULL ) && ( Fd_ATib ( *R ) == NULL ))   {
           Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
           S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
           S_M.Champ2 = True ;
           Init_struct_Tib ( M , S_M )  ;
           Aff_info_ATib ( *R , M ) ;
           }
         else
           {
           if( Fg_ATib ( *R ) == NULL)   {
             if( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) == True)   {
               Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
               S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
               S_M.Champ2 = True ;
               Init_struct_Tib ( M , S_M )  ;
               Aff_info_ATib ( *R , M ) ;
              
             } ;
             }
           else
             {
             if( Fd_ATib ( *R ) == NULL)   {
               if( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) == True)   {
                 Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
                 S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
                 S_M.Champ2 = True ;
                 Init_struct_Tib ( M , S_M )  ;
                 Aff_info_ATib ( *R , M ) ;
                
               } ;
               }
             else
               {
               if( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) == True)   {
                 if( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) == True)   {
                   Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
                   S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
                   S_M.Champ2 = True ;
                   Init_struct_Tib ( M , S_M )  ;
                   Aff_info_ATib ( *R , M ) ;
                  
                 } ;
                
               } ;
              
             } ;
            
           } ;
          
         } ;
         _Px1 =  Fg_ATib ( *R ) ;
         Take_leafs_2 ( &_Px1, & *P ) ;
         _Px2 =  Fd_ATib ( *R ) ;
         Take_leafs_2 ( &_Px2, & *P ) ;
        
       } ;
      
     } ;
    
    }
  /*---------------------------------------------------*/
  void Travers_4 (Pointeur_ATib *R , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Pointeur_Pi P2=NULL;

      /** Corps du module **/
     Creerpile_Pi (& P2 ) ;
     while( ( ( Fg_ATib ( *R ) != NULL ) || ( Fd_ATib ( *R ) != NULL ) ) && ( ( Fg_ATib ( *R ) != NULL ) || ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) != True ) ) && ( ( Fd_ATib ( *R ) != NULL ) || ( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) != True ) ) && ( ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) != True ) || ( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) != True ) ))  {
       Take_leafs_4 ( & *R , & *P ) ;
      
     } ;
     Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
     while( Pilevide_Pi ( *P ) == False)  {
       Depiler_Pi (& *P , &H ) ;
       Empiler_Pi (& P2 , H ) ;
      
     } ;
     *P  =  P2 ;
    
    }
  /*-----------------------------------------------------*/
  void Take_leafs_4 (Pointeur_ATib *R , Pointeur_Pi *P)
    {
      /** Variables locales **/
      Typestr_Tib M;
      Type_Tib S_M;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     M = malloc(sizeof(Type_Tib));
     if( ( *R != NULL ))   {
       if( ( Struct2_Tib ( Info_ATib ( *R )  ) == False ))   {
         if( ( Fg_ATib ( *R ) == NULL ) && ( Fd_ATib ( *R ) == NULL ))   {
           Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
           S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
           S_M.Champ2 = True ;
           Init_struct_Tib ( M , S_M )  ;
           Aff_info_ATib ( *R , M ) ;
           }
         else
           {
           if( Fg_ATib ( *R ) == NULL)   {
             if( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) == True)   {
               Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
               S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
               S_M.Champ2 = True ;
               Init_struct_Tib ( M , S_M )  ;
               Aff_info_ATib ( *R , M ) ;
              
             } ;
             }
           else
             {
             if( Fd_ATib ( *R ) == NULL)   {
               if( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) == True)   {
                 Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
                 S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
                 S_M.Champ2 = True ;
                 Init_struct_Tib ( M , S_M )  ;
                 Aff_info_ATib ( *R , M ) ;
                
               } ;
               }
             else
               {
               if( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) == True)   {
                 if( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) == True)   {
                   Empiler_Pi (& *P , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
                   S_M.Champ1 = Struct1_Tib(Info_ATib(*R)) ;
                   S_M.Champ2 = True ;
                   Init_struct_Tib ( M , S_M )  ;
                   Aff_info_ATib ( *R , M ) ;
                  
                 } ;
                
               } ;
              
             } ;
            
           } ;
          
         } ;
         _Px1 =  Fd_ATib ( *R ) ;
         Take_leafs_4 ( &_Px1, & *P ) ;
         _Px2 =  Fg_ATib ( *R ) ;
         Take_leafs_4 ( &_Px2, & *P ) ;
        
       } ;
      
     } ;
    
    }
  /*---------------------------------------------------------------------------*/
  bool  Verify_2 (Pointeur_ATib *R , Pointeur_Pi *P) 
    {
      /** Variables locales **/
      bool  Verify_22 ;
      Pointeur_ATib R1=NULL;
      Pointeur_Pi Ph=NULL;
      Pointeur_Pi Ph1=NULL;
      int N;
      int N1;

      /** Corps du module **/
     Creerpile_Pi (& Ph ) ;
     Creerpile_Pi (& Ph1 ) ;
     Verify_22  =  True ;
     while( ( Fg_ATib ( *R ) != NULL ) || ( Fd_ATib ( *R ) != NULL ))  {
       Delete_leafs_2 ( & *R , & Ph ) ;
      
     } ;
     Empiler_Pi (& Ph , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
     Liberernoeud_ATib ( *R ) ;
     *R  =  NULL ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &N ) ;
       Empiler_Pi (& Ph1 , N ) ;
      
     } ;
     while( ( Pilevide_Pi ( *P ) == False ) && ( Pilevide_Pi ( Ph1 ) == False ))  {
       Depiler_Pi (& *P , &N ) ;
       Empiler_Pi (& Ph , N ) ;
       Depiler_Pi (& Ph1 , &N1 ) ;
       if( N != N1)   {
         Verify_22  =  False ;
        
       } ;
      
     } ;
     if( ( Pilevide_Pi ( Ph1 ) == False ) || ( Pilevide_Pi ( *P ) == False ))   {
       Verify_22  =  False ;
      
     } ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &N ) ;
       Empiler_Pi (& *P , N ) ;
      
     } ;
    
     return Verify_22 ;
    }
  /*---------------------------------------------------------------------*/
  void Delete_leafs_2 (Pointeur_ATib *R , Pointeur_Pi *P2)
    {
      /** Variables locales **/
      Pointeur_ATib R1=NULL;
      int N;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL)   {
       if( ( Fg_ATib ( *R ) == NULL ) && ( Fd_ATib ( *R ) == NULL ))   {
         Empiler_Pi (& *P2 , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
         R1  =  Pere_ATib ( *R ) ;
         if( Fg_ATib ( R1 ) == *R)   {
           Aff_fg_ATib ( R1 , NULL ) ;
           }
         else
           {
           Aff_fd_ATib ( R1 , NULL ) ;
          
         } ;
         Liberernoeud_ATib ( *R ) ;
         }
       else
         {
         _Px1 =  Fg_ATib ( *R ) ;
         Delete_leafs_2 ( &_Px1, & *P2 ) ;
         _Px2 =  Fd_ATib ( *R ) ;
         Delete_leafs_2 ( &_Px2, & *P2 ) ;
        
       }
     } ;
    
    }
  /*-----------------------------------------------------------------------*/
  bool  Verify_4 (Pointeur_ATib *R , Pointeur_Pi *P) 
    {
      /** Variables locales **/
      bool  Verify_42 ;
      Pointeur_ATib R1=NULL;
      Pointeur_Pi Ph=NULL;
      Pointeur_Pi Ph1=NULL;
      int N;
      int N1;

      /** Corps du module **/
     Creerpile_Pi (& Ph ) ;
     Creerpile_Pi (& Ph1 ) ;
     Verify_42  =  True ;
     while( ( Fg_ATib ( *R ) != NULL ) || ( Fd_ATib ( *R ) != NULL ))  {
       Delete_leafs_4 ( & *R , & Ph ) ;
      
     } ;
     Empiler_Pi (& Ph , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
     Liberernoeud_ATib ( *R ) ;
     *R  =  NULL ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &N ) ;
       Empiler_Pi (& Ph1 , N ) ;
      
     } ;
     while( ( Pilevide_Pi ( *P ) == False ) && ( Pilevide_Pi ( Ph1 ) == False ))  {
       Depiler_Pi (& *P , &N ) ;
       Empiler_Pi (& Ph , N ) ;
       Depiler_Pi (& Ph1 , &N1 ) ;
       if( N != N1)   {
         Verify_42  =  False ;
        
       } ;
      
     } ;
     if( ( Pilevide_Pi ( Ph1 ) == False ) || ( Pilevide_Pi ( *P ) == False ))   {
       Verify_42  =  False ;
      
     } ;
     while( Pilevide_Pi ( Ph ) == False)  {
       Depiler_Pi (& Ph , &N ) ;
       Empiler_Pi (& *P , N ) ;
      
     } ;
    
     return Verify_42 ;
    }
  /*---------------------------------------------------------------------*/
  void Delete_leafs_4 (Pointeur_ATib *R , Pointeur_Pi *P2)
    {
      /** Variables locales **/
      Pointeur_ATib R1=NULL;
      int N;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL)   {
       if( ( Fg_ATib ( *R ) == NULL ) && ( Fd_ATib ( *R ) == NULL ))   {
         Empiler_Pi (& *P2 , Struct1_Tib ( Info_ATib ( *R )  ) ) ;
         R1  =  Pere_ATib ( *R ) ;
         if( Fg_ATib ( R1 ) == *R)   {
           Aff_fg_ATib ( R1 , NULL ) ;
           }
         else
           {
           Aff_fd_ATib ( R1 , NULL ) ;
          
         } ;
         Liberernoeud_ATib ( *R ) ;
         }
       else
         {
         _Px1 =  Fd_ATib ( *R ) ;
         Delete_leafs_4 ( &_Px1, & *P2 ) ;
         _Px2 =  Fg_ATib ( *R ) ;
         Delete_leafs_4 ( &_Px2, & *P2 ) ;
        
       }
     } ;
    
    }
   /*display of the tree*/
int lProfi[MAXHEI];
int rProfi[MAXHEI];

#define GAP 3

typedef struct AscNode {
    struct AscNode* left, * right;
    int edgeLen;
    int height;
    int labL;
    int parentDir;
    char label[11];
} AscNode;

int printNext;

AscNode* buildTreeRec(Pointeur_ATib t);
AscNode* buildTree(Pointeur_ATib t);
void freeTree(AscNode* node);
void calcLProfile(AscNode* node, int x, int y);
void calcRProfile(AscNode* node, int x, int y);
void calcEdgeLengths(AscNode* node);
void printLvl(AscNode* node, int x, int level);
void showTree(Pointeur_ATib root);

AscNode* buildTreeRec(Pointeur_ATib t) {
    AscNode* node;

    if (t == NULL) return NULL;

    node = (AscNode*)malloc(sizeof(AscNode));
    node->left = buildTreeRec(t->Fg);
    node->right = buildTreeRec(t->Fd);

    if (node->left != NULL) node->left->parentDir = -1;
    if (node->right != NULL) node->right->parentDir = 1;

    sprintf(node->label, "%d", t->Val->Champ1);
    node->labL = strlen(node->label);

    return node;
}

AscNode* buildTree(Pointeur_ATib t) {
    AscNode* node;
    if (t == NULL) return NULL;
    node = buildTreeRec(t);
    node->parentDir = 0;
    return node;
}

void freeTree(AscNode* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void calcLProfile(AscNode* node, int x, int y) {
    int i, Left;
    if (node == NULL) return;
    Left = (node->parentDir == -1);
    lProfi[y] = MIN(lProfi[y], x - ((node->labL - Left) / 2));
    if (node->left != NULL) {
        for (i = 1; i <= node->edgeLen && y + i < MAXHEI; i++) {
            lProfi[y + i] = MIN(lProfi[y + i], x - i);
        }
    }
    calcLProfile(node->left, x - node->edgeLen - 1, y + node->edgeLen + 1);
    calcLProfile(node->right, x + node->edgeLen + 1, y + node->edgeLen + 1);
}

void calcRProfile(AscNode* node, int x, int y) {
    int i, notLeft;
    if (node == NULL) return;
    notLeft = (node->parentDir != -1);
    rProfi[y] = MAX(rProfi[y], x + ((node->labL - notLeft) / 2));
    if (node->right != NULL) {
        for (i = 1; i <= node->edgeLen && y + i < MAXHEI; i++) {
            rProfi[y + i] = MAX(rProfi[y + i], x + i);
        }
    }
    calcRProfile(node->left, x - node->edgeLen - 1, y + node->edgeLen + 1);
    calcRProfile(node->right, x + node->edgeLen + 1, y + node->edgeLen + 1);
}

void calcEdgeLengths(AscNode* node) {
    int height, minHei, i, delta;
    if (node == NULL) return;
    calcEdgeLengths(node->left);
    calcEdgeLengths(node->right);

    if (node->right == NULL && node->left == NULL) {
        node->edgeLen = 0;
    } else {
        if (node->left != NULL) {
            for (i = 0; i < node->left->height && i < MAXHEI; i++) {
                rProfi[i] = -INFI;
            }
            calcRProfile(node->left, 0, 0);
            minHei = node->left->height;
        } else {
            minHei = 0;
        }
        if (node->right != NULL) {
            for (i = 0; i < node->right->height && i < MAXHEI; i++) {
                lProfi[i] = INFI;
            }
            calcLProfile(node->right, 0, 0);
            minHei = MIN(node->right->height, minHei);
        } else {
            minHei = 0;
        }
        delta = 4;
        for (i = 0; i < minHei; i++) {
            delta = MAX(delta, GAP + 1 + rProfi[i] - lProfi[i]);
        }
        if (((node->left != NULL && node->left->height == 1) ||
            (node->right != NULL && node->right->height == 1)) && delta > 4) {
            delta--;
        }
        node->edgeLen = ((delta + 1) / 2) - 1;
    }
    height = 1;
    if (node->left != NULL) {
        height = MAX(node->left->height + node->edgeLen + 1, height);
    }
    if (node->right != NULL) {
        height = MAX(node->right->height + node->edgeLen + 1, height);
    }
    node->height = height;
}

void printLvl(AscNode* node, int x, int level) {
    int i, Left;
    if (node == NULL) return;
    Left = (node->parentDir == -1);
    if (level == 0) {
        for (i = 0; i < (x - printNext - ((node->labL - Left) / 2)); i++) {
            printf(" ");
        }
        printNext += i;
        printf("%s", node->label);
        printNext += node->labL;
    } else if (node->edgeLen >= level) {
        if (node->left != NULL) {
            for (i = 0; i < (x - printNext - level); i++) {
                printf(" ");
            }
            printNext += i;
            printf("/");
            printNext++;
        }
        if (node->right != NULL) {
            for (i = 0; i < (x - printNext + level); i++) {
                printf(" ");
            }
            printNext += i;
            printf("\\");
            printNext++;
        }
    } else {
        printLvl(node->left, x - node->edgeLen - 1, level - node->edgeLen - 1);
        printLvl(node->right, x + node->edgeLen + 1, level - node->edgeLen - 1);
    }
}

void showTree(Pointeur_ATib root) {
    AscNode* ascRoot;
    int minX, i;
    if (root == NULL) return;
    ascRoot = buildTree(root);
    calcEdgeLengths(ascRoot);
    for (i = 0; i < ascRoot->height && i < MAXHEI; i++) {
        lProfi[i] = INFI;
    }
    calcLProfile(ascRoot, 0, 0);
    minX = 0;
    for (i = 0; i < ascRoot->height && i < MAXHEI; i++) {
        minX = MIN(minX, lProfi[i]);
    }
    for (i = 0; i < ascRoot->height; i++) {
        printNext = 0;
        printLvl(ascRoot, -minX, i);
        printf("\n");
    }
    if (ascRoot->height >= MAXHEI) {
        printf("(Tree is taller than %d, will be truncated)\n", MAXHEI);
    }
    freeTree(ascRoot);
}


  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     R = malloc(sizeof(Type_Tib));
     Creerpile_Pi (& P1 ) ;
     Creerpile_Pi (& P2 ) ;
     for( C  =  1 ;C <=  10 ; ++C){
       Create_trees ( & L , & L1 ) ;
       if( Verifie_arb ( & L ))   {

       
       
        printf("\n\nFor tree %d:\n",C);
         showTree(L);
         Travers_1 ( & L , & P1 ) ;
         printf ( " %s", "\npour travers 1:" );
         if( Verify_1(&P1,&L)==1){printf("true\n");}else{printf("false\n");}
         printf ( " %s\n", "la liste:" ) ;
         while( Pilevide_Pi ( P1 ) == False)  {
           Depiler_Pi (& P1 , &H ) ;
           printf ( " %d,", H ) ;
          
         } ;
         
         Viderpile ( & P1 ) ;
         Initialize_tree ( & L ) ;
         Travers_2 ( & L , & P1 ) ;
         printf ( " %s", "\npour travers 2:" );

if( Verify_2(&L,&P1)==1){printf("true\n");}else{printf("false\n");}
         printf ( " %s\n", "la liste:" ) ;
         while( Pilevide_Pi ( P1 ) == False)  {
           Depiler_Pi (& P1 , &H ) ;
           printf ( " %d,", H ) ;
          
         } ;
         Viderpile ( & P1 ) ;
         Travers_3 ( & L1 , & P1 ) ;
         printf ( " %s", "\npour travers 3:" );
         if(  Verify_3(&P1,&L1)==1){printf("true\n");}else{printf("false\n");}
         printf ( " %s\n", "la liste:" ) ;
         while( Pilevide_Pi ( P1 ) == False)  {
           Depiler_Pi (& P1 , &H ) ;
           printf ( " %d,", H ) ;
          
         } ;
         Viderpile ( & P1 ) ;
         Initialize_tree ( & L1 ) ;
         Travers_4 ( & L1 , & P1 ) ;
         printf ( " %s", "\npour travers 4:" );
         if(  Verify_4(&L1,&P1)==1){printf("true\n");}else{printf("false\n");}
         printf ( " %s\n", "la liste:" ) ;
         while( Pilevide_Pi ( P1 ) == False)  {
           Depiler_Pi (& P1 , &H ) ;
           printf ( " %d,", H ) ;
          
         };
         }
       else
         {
         C  =  C - 1 ;
        
       } ;
       Viderpile ( & P1 ) ;
       printf("\n");
       printf("press any key to go to next tree...");
       getch();
       system("cls");
     } ;
     printf("\n");
    
   
      system("PAUSE");
      return 0;
    } 