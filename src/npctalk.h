#pragma once
#ifndef NPCTALK_H
#define NPCTALK_H

#include "type_id.h"

class npc;
class time_duration;

namespace talk_function
{
void nothing( npc & );
void assign_mission( npc & );
void mission_success( npc & );
void mission_failure( npc & );
void clear_mission( npc & );
void mission_reward( npc & );
void mission_favor( npc & );
void give_equipment( npc & );
void give_aid( npc & );
void give_all_aid( npc & );
void buy_horse( npc & );
void buy_cow( npc & );
void buy_chicken( npc & );
void bionic_install( npc & );
void bionic_remove( npc & );

void buy_haircut( npc & );
void buy_shave( npc & );
void morale_chat( npc & );
void morale_chat_activity( npc & );
void buy_10_logs( npc & );
void buy_100_logs( npc & );
void start_trade( npc & );
void goto_location( npc & );
void assign_base( npc & );
void assign_guard( npc & );
void stop_guard( npc & );
void end_conversation( npc & );
void insult_combat( npc & );
void reveal_stats( npc & );
void follow( npc & );                // p becomes a member of your_followers
void follow_only( npc & );           // p starts following you
void deny_follow( npc & );           // p gets "asked_to_follow"
void deny_lead( npc & );             // p gets "asked_to_lead"
void deny_equipment( npc & );        // p gets "asked_for_item"
void deny_train( npc & );            // p gets "asked_to_train"
void deny_personal_info( npc & );    // p gets "asked_personal_info"
void hostile( npc & );               // p turns hostile to u
void flee( npc & );
void leave( npc & );                 // p becomes indifferent
void stop_following( npc & );
void stranger_neutral( npc & );      // p is now neutral towards you

void start_mugging( npc & );
void player_leaving( npc & );

void drop_weapon( npc & );
void player_weapon_away( npc & );
void player_weapon_drop( npc & );

void lead_to_safety( npc & );
void start_training( npc & );

void wake_up( npc & );
void copy_npc_rules( npc &p );
void set_npc_pickup( npc &p );
void npc_die( npc &p );
void npc_thankful( npc &p );
void clear_overrides( npc &p );
}

time_duration calc_skill_training_time( const npc &p, const skill_id &skill );
int calc_skill_training_cost( const npc &p, const skill_id &skill );
time_duration calc_ma_style_training_time( const npc &, const matype_id & /* id */ );
int calc_ma_style_training_cost( const npc &p, const matype_id & /* id */ );
#endif
