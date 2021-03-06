/***************************************************************************
 *  File: olc.h                                                            *
 *                                                                         *
 *  Much time and thought has gone into this software and you are          *
 *  benefitting.  We hope that you share your changes too.  What goes      *
 *  around, comes around.                                                  *
 *                                                                         *
 *  This code was freely distributed with the The Isles 1.1 source code,   *
 *  and has been used here for OLC - OLC would not be what it is without   *
 *  all the previous coders who released their source code.                *
 *                                                                         *
 ***************************************************************************/
/*
 * This is a header file for all the OLC files.  Feel free to copy it into
 * merc.h if you wish.  Many of these routines may be handy elsewhere in
 * the code.  -Jason Dinkel
 */

#if !defined(_OLC_H)
#define _OLC_H

#if !defined(_TABLES_H)
#include "tables.h"
#endif // _TABLES_H

#if !defined(_TABLESAVE_H)
#include "tablesave.h"
#endif // _TABLESAVE_H

char * flag_string( const struct flag_type *, long );
char * background_flag_string( const struct background_type *, long );

/*
 * The version info.  Please use this info when reporting bugs.
 * It is displayed in the game by typing 'version' while editing.
 * Do not remove these from the code - by request of Jason Dinkel
 */
#define OLC_VERSION	"ILAB Online Creation [Beta 1.0, ROM 2.3 modified]\n\r" \
			"     Port a ROM 2.4 v2.00\n\r"
#define OLC_AUTHOR	"     By Jason(jdinkel@mines.colorado.edu)\n\r" \
                	"     Modified for use with ROM 2.3\n\r"        \
                	"     By Hans Birkeland (hansbi@ifi.uio.no)\n\r" \
                	"     Modificado para uso en ROM 2.4v4\n\r"	\
                	"     Por Birdie (itoledo@geocities.com)\n\r"
#define OLC_DATE	"     (Apr. 7, 1995 - ROM mod, Apr 16, 1995)\n\r" \
			"     (Port a ROM 2.4 - Nov 2, 1996)\n\r"
#define OLC_CREDITS	"     Original by Surreality(cxw197@psu.edu) and Locke(locke@lm.com)"



/*
 * New typedefs.
 */
typedef	bool OLC_FUN		args( ( CHAR_DATA *ch, char *argument ) );
#define DECLARE_OLC_FUN( fun )	OLC_FUN    fun

typedef bool ED_FUN		args( ( char *, CHAR_DATA *, char *, void *, const void * ) );
#define DECLARE_ED_FUN( fun )	ED_FUN	   fun

#define ED_FUN_DEC(blah)	bool blah ( char * n_fun, CHAR_DATA *ch, char *argument, void *arg, const void *par )

/* Command procedures needed ROM OLC */
DECLARE_DO_FUN(    do_help    );
DECLARE_SPELL_FUN( spell_null );





/*
 * Connected states for editor.
 */
#define ED_NONE		0
#define	ED_AREA		1
#define	ED_ROOM		2
#define	ED_OBJECT	3
#define	ED_MOBILE	4
#define	ED_PROG		5
#define	ED_GUILD	6
#define	ED_RACE		7
#define	ED_SOCIAL	8
#define ED_SKILL	9
#define ED_CMD		10
#define ED_GROUP	11
#define ED_HELP		13
#define ED_SGUILD 	14
#define ED_TGUILD 	15
#define ED_POLL		16

/*
 * Interpreter Prototypes
 */
void    aedit           args( ( CHAR_DATA *ch, char *argument ) );
void    redit           args( ( CHAR_DATA *ch, char *argument ) );
void    medit           args( ( CHAR_DATA *ch, char *argument ) );
void    oedit           args( ( CHAR_DATA *ch, char *argument ) );
void    pedit          args( ( CHAR_DATA *ch, char *argument ) );
void	cedit		args( ( CHAR_DATA *ch, char *argument ) );
void	raedit		args( ( CHAR_DATA *ch, char *argument ) );
void	sedit		args( ( CHAR_DATA *ch, char *argument ) );
void	skedit		args( ( CHAR_DATA *ch, char *argument ) );
void	cmdedit		args( ( CHAR_DATA *ch, char *argument ) );
void	gedit		args( ( CHAR_DATA *ch, char *argument ) );
void	scedit		args( ( CHAR_DATA *ch, char *argument ) );
void	hedit		args( ( CHAR_DATA *ch, char *argument ) );
void	guildedit		args( ( CHAR_DATA *ch, char *argument ) );
void	sguildedit		args( ( CHAR_DATA *ch, char *argument ) );
void	tguildedit		args( ( CHAR_DATA *ch, char *argument ) );

/*
 * OLC Constants
 */
#define MAX_MOB	1		/* Default maximum number for resetting mobs */

#define	MIN_PEDIT_SECURITY	1
#define	MIN_SKEDIT_SECURITY	5
#define MIN_CMDEDIT_SECURITY	7
#define MIN_SEDIT_SECURITY	2


/*
 * Structure for an OLC editor command.
 */
struct olc_cmd_type
{
    char * const	name;
    OLC_FUN *		olc_fun;
};


struct olc_comm_type
{
	char *		name;
	void *		argument;
	ED_FUN *	function;
	const void *	parameter;
};

extern	const	struct	olc_comm_type	mob_olc_comm_table	[];
extern	const	struct	olc_comm_type	obj_olc_comm_table	[];
extern	const	struct	olc_comm_type	room_olc_comm_table	[];
extern	const	struct	olc_comm_type	skill_olc_comm_table	[];
extern	const	struct	olc_comm_type	race_olc_comm_table	[];
extern	const	struct	olc_comm_type	cmd_olc_comm_table	[];
extern	const	struct	olc_comm_type	prog_olc_comm_table	[];
extern	const	struct	olc_comm_type	social_olc_comm_table	[];


bool procesar_comando_olc( CHAR_DATA *, char * argument, const struct olc_comm_type * );

/*
 * Structure for an OLC editor startup command.
 */
struct	editor_cmd_type
{
    char * const	name;
    DO_FUN *		do_fun;
};



/*
 * Utils.
 */
AREA_DATA *	get_vnum_area	args ( ( int vnum ) );
AREA_DATA *	get_area_data	args ( ( int vnum ) );
int		flag_value	args ( ( const struct flag_type *flag_table, char *argument) );
int       background_flag_value args ( ( const struct background_type *flag_table, char *argument) );
void		add_reset	args ( ( ROOM_INDEX_DATA *,
					RESET_DATA *, int ) );
void		set_editor	args ( ( DESCRIPTOR_DATA *, int, void * ) );



/*
 * Interpreter Table Prototypes
 */
extern const struct olc_cmd_type	aedit_table[];
extern const struct olc_cmd_type	cedit_table[];
/* extern const struct olc_cmd_type	raedit_table[]; */
extern const struct olc_cmd_type	gedit_table[];
extern const struct olc_cmd_type	scedit_table[];
extern const struct olc_cmd_type	hedit_table[];
extern const struct olc_cmd_type	guildedit_table[];
extern const struct olc_cmd_type	sguildedit_table[];
extern const struct olc_cmd_type	tguildedit_table[];
extern const struct olc_cmd_type 	polledit_table[];


/*
 * Editor Commands.
 */
DECLARE_DO_FUN( do_aedit        );
DECLARE_DO_FUN( do_redit        );
DECLARE_DO_FUN( do_oedit        );
DECLARE_DO_FUN( do_medit        );
DECLARE_DO_FUN( do_pedit       );
DECLARE_DO_FUN( do_cedit	);
DECLARE_DO_FUN( do_raedit	);
DECLARE_DO_FUN( do_sedit	);
DECLARE_DO_FUN( do_skedit	);
DECLARE_DO_FUN( do_cmdedit	);
DECLARE_DO_FUN( do_gedit	);
DECLARE_DO_FUN( do_scedit	);
DECLARE_DO_FUN( do_hedit	);
DECLARE_DO_FUN( do_guildedit	);
DECLARE_DO_FUN( do_sguildedit	);
DECLARE_DO_FUN( do_tguildedit );
DECLARE_DO_FUN( do_polledit );

/*
 * General Functions
 */
bool show_commands		args ( ( CHAR_DATA *ch, char *argument ) );
bool show_cmd_commands		args ( ( CHAR_DATA *ch, char *argument ) );
bool show_help			args ( ( CHAR_DATA *ch, char *argument ) );
bool edit_done			args ( ( CHAR_DATA *ch ) );
bool show_version		args ( ( CHAR_DATA *ch, char *argument ) );
unsigned int findnextroom(unsigned int curvnum, unsigned int maxvnum);

/*
 * Area Editor Prototypes
 */
DECLARE_OLC_FUN( aedit_show		);
DECLARE_OLC_FUN( aedit_create		);
DECLARE_OLC_FUN( aedit_name		);
DECLARE_OLC_FUN( aedit_file		);
DECLARE_OLC_FUN( aedit_age		);
/* DECLARE_OLC_FUN( aedit_recall	);       ROM OLC */
DECLARE_OLC_FUN( aedit_reset		);
DECLARE_OLC_FUN( aedit_security		);
DECLARE_OLC_FUN( aedit_builder		);
DECLARE_OLC_FUN( aedit_vnum		);
DECLARE_OLC_FUN( aedit_lvnum		);
DECLARE_OLC_FUN( aedit_uvnum		);
DECLARE_OLC_FUN( aedit_credits		);
DECLARE_OLC_FUN( aedit_lowrange		);
DECLARE_OLC_FUN( aedit_highrange	);
DECLARE_OLC_FUN( aedit_delete		);


/*
 * Room Editor Prototypes
 */
DECLARE_OLC_FUN( redit_show		);
DECLARE_OLC_FUN( redit_create		);
DECLARE_OLC_FUN( redit_format		);
DECLARE_OLC_FUN( redit_mreset		);
DECLARE_OLC_FUN( redit_oreset		);
DECLARE_OLC_FUN( redit_mlist		);
DECLARE_OLC_FUN( redit_rlist		);
DECLARE_OLC_FUN( redit_addrprog		);
DECLARE_OLC_FUN( redit_listreset	);
DECLARE_OLC_FUN( redit_checkmob		);
DECLARE_OLC_FUN( redit_checkobj		);
DECLARE_OLC_FUN( redit_copy		);
DECLARE_OLC_FUN( redit_checkrooms	);
DECLARE_OLC_FUN( redit_clean		);

/*
 * Object Editor Prototypes
 */
DECLARE_OLC_FUN( oedit_show		);
DECLARE_OLC_FUN( oedit_create		);
DECLARE_OLC_FUN( oedit_addaffect	);
DECLARE_OLC_FUN( oedit_delaffect	);
DECLARE_OLC_FUN( oedit_addapply		);
DECLARE_OLC_FUN( oedit_addoprog		);
DECLARE_OLC_FUN( oedit_copy		);

/* Editor de mobs */
DECLARE_OLC_FUN( medit_show		);
DECLARE_OLC_FUN( medit_group		);
DECLARE_OLC_FUN( medit_copy		);

/** Guild Editor Prototypes
 */
DECLARE_OLC_FUN( guildedit_flags		);
DECLARE_OLC_FUN( guildedit_rank		);
DECLARE_OLC_FUN( guildedit_skill		);
DECLARE_OLC_FUN( guildedit_show		);
DECLARE_OLC_FUN( guildedit_name		);
DECLARE_OLC_FUN( guildedit_whoname		);
DECLARE_OLC_FUN( guildedit_create		);
DECLARE_OLC_FUN( guildedit_list		);
DECLARE_OLC_FUN( guildedit_rooms            );
DECLARE_OLC_FUN( guildedit_ml               );

/** Sub Guild Editor Prototypes
 */
DECLARE_OLC_FUN( sguildedit_flags		);
DECLARE_OLC_FUN( sguildedit_rank		);
DECLARE_OLC_FUN( sguildedit_skill		);
DECLARE_OLC_FUN( sguildedit_show		);
DECLARE_OLC_FUN( sguildedit_name		);
DECLARE_OLC_FUN( sguildedit_whoname		);
DECLARE_OLC_FUN( sguildedit_create		);
DECLARE_OLC_FUN( sguildedit_list		);
DECLARE_OLC_FUN( sguildedit_rooms            );
DECLARE_OLC_FUN( sguildedit_ml               );

/** Sub Sub Guild Editor Prototypes
 */
DECLARE_OLC_FUN( tguildedit_flags		);
DECLARE_OLC_FUN( tguildedit_rank		);
DECLARE_OLC_FUN( tguildedit_skill		);
DECLARE_OLC_FUN( tguildedit_show		);
DECLARE_OLC_FUN( tguildedit_name		);
DECLARE_OLC_FUN( tguildedit_whoname		);
DECLARE_OLC_FUN( tguildedit_create		);
DECLARE_OLC_FUN( tguildedit_list		);
DECLARE_OLC_FUN( tguildedit_rooms            );
DECLARE_OLC_FUN( tguildedit_ml               );

/*
 * Race editor.
 */
DECLARE_OLC_FUN( raedit_show		);
DECLARE_OLC_FUN( raedit_new		);
DECLARE_OLC_FUN( raedit_list		);
DECLARE_OLC_FUN( raedit_cmult		);
DECLARE_OLC_FUN( raedit_stats		);
DECLARE_OLC_FUN( raedit_spheres    );
DECLARE_OLC_FUN( raedit_maxstats	);
DECLARE_OLC_FUN( raedit_skills	);

/*
 * Social editor.
 */
DECLARE_OLC_FUN( sedit_show		);
DECLARE_OLC_FUN( sedit_cnoarg		);
DECLARE_OLC_FUN( sedit_onoarg		);
DECLARE_OLC_FUN( sedit_cfound		);
DECLARE_OLC_FUN( sedit_ofound		);
DECLARE_OLC_FUN( sedit_vfound		);
DECLARE_OLC_FUN( sedit_cself		);
DECLARE_OLC_FUN( sedit_oself		);
DECLARE_OLC_FUN( sedit_new		);
DECLARE_OLC_FUN( sedit_delete		); 

/*
 * Skill editor.
 */
DECLARE_OLC_FUN( skedit_show		);
DECLARE_OLC_FUN( skedit_name		);
DECLARE_OLC_FUN( skedit_nombre		);
DECLARE_OLC_FUN( skedit_slot		);
DECLARE_OLC_FUN( skedit_sphere     );
DECLARE_OLC_FUN( skedit_level		);
DECLARE_OLC_FUN( skedit_rating		);
DECLARE_OLC_FUN( skedit_list		);
DECLARE_OLC_FUN( skedit_gsn		);
DECLARE_OLC_FUN( skedit_spell		);
DECLARE_OLC_FUN( skedit_new		);
DECLARE_OLC_FUN( skedit_script		);
DECLARE_OLC_FUN( skedit_type		);
DECLARE_OLC_FUN( skedit_free		);
DECLARE_OLC_FUN( skedit_cmsg		);
DECLARE_OLC_FUN( skedit_callback	);


/*
 * Editor de comandos.
 */
DECLARE_OLC_FUN( cmdedit_show		);
DECLARE_OLC_FUN( cmdedit_name		);
DECLARE_OLC_FUN( cmdedit_function	);
DECLARE_OLC_FUN( cmdedit_level		);
DECLARE_OLC_FUN( cmdedit_list		);
DECLARE_OLC_FUN( cmdedit_new		);
DECLARE_OLC_FUN( cmdedit_delete		);

/*
 * Editor de grupos.
 */
DECLARE_OLC_FUN( gedit_show		);
DECLARE_OLC_FUN( gedit_name		);
DECLARE_OLC_FUN( gedit_rating		);
DECLARE_OLC_FUN( gedit_spell		);
DECLARE_OLC_FUN( gedit_list		);

/*
 * Editor de scripts.
 */
DECLARE_OLC_FUN( scedit_show		);
DECLARE_OLC_FUN( scedit_new		);
DECLARE_OLC_FUN( scedit_add		);
DECLARE_OLC_FUN( scedit_remove		);
DECLARE_OLC_FUN( scedit_delete		);
DECLARE_OLC_FUN( scedit_list		);

/*
 * Editor de helps.
 */
DECLARE_OLC_FUN( hedit_show		);
DECLARE_OLC_FUN( hedit_keyword		);
DECLARE_OLC_FUN( hedit_text		);
DECLARE_OLC_FUN( hedit_new		);
DECLARE_OLC_FUN( hedit_level		);
DECLARE_OLC_FUN( hedit_delete		);
DECLARE_OLC_FUN( hedit_list		);


/*
 * Voting Functions
 */
/* Poll editor */
DECLARE_OLC_FUN( polledit_show       );
DECLARE_OLC_FUN( polledit_list       );
DECLARE_OLC_FUN( polledit_create     );
DECLARE_OLC_FUN( polledit_topic      );
DECLARE_OLC_FUN( polledit_to         );
DECLARE_OLC_FUN( polledit_open       );
DECLARE_OLC_FUN( polledit_close      );
DECLARE_OLC_FUN( polledit_reopen     );
DECLARE_OLC_FUN( polledit_choice     );
DECLARE_OLC_FUN( polledit_publish    );
DECLARE_OLC_FUN( polledit_delete     );
DECLARE_OLC_FUN( polledit_credits    );

/*
 * Editores.
 */
DECLARE_ED_FUN( ed_line_string		);
DECLARE_ED_FUN( ed_desc			);
DECLARE_ED_FUN( ed_bool			);
DECLARE_ED_FUN( ed_flag_toggle		);
DECLARE_ED_FUN( ed_flag_set_long	);
DECLARE_ED_FUN( ed_flag_set_sh		);
DECLARE_ED_FUN(ed_background_set_sh);
DECLARE_ED_FUN( ed_number_niv		);
DECLARE_ED_FUN( ed_mob_level		);
DECLARE_ED_FUN( ed_number_align		);
DECLARE_ED_FUN( ed_number_s_pos		);
DECLARE_ED_FUN( ed_number_pos		);
DECLARE_ED_FUN( ed_number_l_pos		);
DECLARE_ED_FUN( ed_object_level		);
DECLARE_ED_FUN( ed_shop			);
DECLARE_ED_FUN( ed_new_mob		);
DECLARE_ED_FUN( ed_commands		);
DECLARE_ED_FUN( ed_gamespec		);
DECLARE_ED_FUN( ed_recval		);
DECLARE_ED_FUN( ed_shintposlookup	);
DECLARE_ED_FUN( ed_shintlookup		);
DECLARE_ED_FUN( ed_sphere          );
DECLARE_ED_FUN( ed_guild           );
DECLARE_ED_FUN( ed_ac			);
DECLARE_ED_FUN( ed_dice			);
DECLARE_ED_FUN( ed_addprog		);
DECLARE_ED_FUN( ed_delprog		);
DECLARE_ED_FUN( ed_script		);
DECLARE_ED_FUN( ed_ed			);
DECLARE_ED_FUN( ed_addaffect		);
DECLARE_ED_FUN( ed_delaffect		);
DECLARE_ED_FUN( ed_addapply		);
DECLARE_ED_FUN( ed_value		);
DECLARE_ED_FUN( ed_new_obj		);
DECLARE_ED_FUN( ed_trap			);
DECLARE_ED_FUN( ed_race			);
DECLARE_ED_FUN( ed_olded		);
DECLARE_ED_FUN( ed_direccion		);
DECLARE_ED_FUN( ed_docomm		);
DECLARE_ED_FUN( ed_olist		);
DECLARE_ED_FUN( ed_objrecval		);

/*
 * Macros
 */

/* Return pointers to what is being edited. */
#define EDIT_MOB(Ch, Mob)	( Mob = (MOB_INDEX_DATA *)Ch->desc->pEdit )
#define EDIT_OBJ(Ch, Obj)	( Obj = (OBJ_INDEX_DATA *)Ch->desc->pEdit )
#define EDIT_ROOM(Ch, Room)	( Room = (ROOM_INDEX_DATA *)Ch->desc->pEdit )
#define EDIT_AREA(Ch, Area)	( Area = (AREA_DATA *)Ch->desc->pEdit )
#define EDIT_CLAN(Ch, Clan)	( Clan = (CLAN_TYPE *)Ch->desc->pEdit )
#define EDIT_RACE(Ch, Race)	( Race = (struct race_type *)Ch->desc->pEdit )
#define EDIT_SOCIAL(Ch, Social)	( Social = (struct social_type *)Ch->desc->pEdit )
#define EDIT_SKILL(Ch, Skill)	( Skill = (struct skill_type *)Ch->desc->pEdit )
#define EDIT_CMD(Ch, Cmd)	( Cmd = (struct cmd_type *)Ch->desc->pEdit )
#define EDIT_GROUP(Ch, Grp)	( Grp = (struct group_type *)Ch->desc->pEdit )
#define EDIT_HELP(Ch, Help)	( Help = (HELP_DATA *)Ch->desc->pEdit )
#define EDIT_PROG(Ch, Code)	( Code = (MPROG_CODE*)Ch->desc->pEdit )

/*
 * Prototypes
 */
/* mem.c - memory prototypes. */
#define ED	EXTRA_DESCR_DATA
RESET_DATA	*new_reset_data		args ( ( void ) );
void		free_reset_data		args ( ( RESET_DATA *pReset ) );
AREA_DATA	*new_area		args ( ( void ) );
void		free_area		args ( ( AREA_DATA *pArea ) );
EXIT_DATA	*new_exit		args ( ( void ) );
void		free_exit		args ( ( EXIT_DATA * ) );
ED 		*new_extra_descr	args ( ( void ) );
void		free_extra_descr	args ( ( ED *pExtra ) );
ROOM_INDEX_DATA *new_room_index		args ( ( void ) );
void		free_room_index		args ( ( ROOM_INDEX_DATA *pRoom ) );
AFFECT_DATA	*new_affect		args ( ( void ) );
void		free_affect		args ( ( AFFECT_DATA* pAf ) );
SHOP_DATA	*new_shop		args ( ( void ) );
void		free_shop		args ( ( SHOP_DATA *pShop ) );
OBJ_INDEX_DATA	*new_obj_index		args ( ( void ) );
void		free_obj_index		args ( ( OBJ_INDEX_DATA *pObj ) );
MOB_INDEX_DATA	*new_mob_index		args ( ( void ) );
void		free_mob_index		args ( ( MOB_INDEX_DATA *pMob ) );
#undef	ED

MPROG_LIST      *new_mprog              args ( ( void ) );
void            free_mprog              args ( ( MPROG_LIST *mp ) );

MPROG_CODE       *new_mpcode             args ( (void) );
void             free_mpcode             args ( ( MPROG_CODE *pMcode));

void		show_liqlist		args ( ( CHAR_DATA *ch ) );
void		show_poslist		args ( ( CHAR_DATA *ch ) );
void		show_damlist		args ( ( CHAR_DATA *ch ) );
void		show_sexlist		args ( ( CHAR_DATA *ch ) );
void		show_sizelist		args ( ( CHAR_DATA *ch ) );
void      show_talent_table   args ( ( CHAR_DATA *ch ) ); 

extern		ROOM_INDEX_DATA 	xRoom;
extern		MOB_INDEX_DATA 		xMob;
extern		OBJ_INDEX_DATA		xObj;

extern	void	InitScreen		args ( ( DESCRIPTOR_DATA * ) );


#endif // _OLC_H
