#include <SDL2/SDL.h>
#include <stdbool.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <fstream>
#include <vector>
#include <iterator>
#include <time.h>
using namespace std;
/* Window resolution */
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

/* Window title */
//#define WINDOW_TITLE "Syndicate"

namespace {
    // New rendering
    SDL_Renderer* gRenderer = NULL;
    SDL_Window *gWindow = NULL;

    // Old rendering
    SDL_Window *window = NULL;
    SDL_Surface* screen = NULL;
    SDL_Surface* screenSurface = NULL;
    std::string choice = "unknown";
    int LOGO_ID_ACTIVE = 0;
    int LOGO_COLOR_ID_ACTIVE = 0;

    const std::string WINDOW_TITLE = "SYNDICATE";
    const std::string MAIN_MENU_TITLE = "MAIN MENU";
    const std::string CONFIGURE_COMPANY_BUTTON_TEXT = "CONFIGURE COMPANY";
    const std::string BEGIN_MISSION_BUTTON_TEXT = "BEGIN MISSION";
    const std::string LOAD_AND_SAVE_GAME_BUTTON_TEXT = "LOAD AND SAVE GAME";
    const std::string RESTART_GAME_BUTTON_TEXT = "RESTART GAME";

    const std::string ACCEPT_BUTTON_TEXT = "ACCEPT";
    const std::string MENU_BUTTON_TEXT = "MENU";

    const std::string COLOR_AND_LOGO_BUTTON_TEXT = "COLOR AND LOGO";
    const std::string COMPANY_NAME_BUTTON_TEXT = "COMPANY NAME";
    const std::string YOUR_NAME_BUTTON_TEXT = "YOUR NAME";
    const std::string SELECT_DETAILS_TO_CHANGE_TEXT = "SELECT DETAILS TO CHANGE";

    const std::string CHANGE_COLOR_AND_LOGO_BUTTON_TEXT = "CHANGE COLOR AND LOGO";
    const std::string COLOR_BUTTON_TEXT = "COLOR";
    const std::string LOGO_BUTTON_TEXT = "LOGO";

    const std::string OK_BUTTON_TEXT = "OK";
    const std::string CANCEL_BUTTON_TEXT = "CANCEL";

    const std::string CHANGE_COMPANY_TEXT = "CHANGE COMPANY NAME";

    const std::string ENTER_YOUR_NAME_TEXT = "ENTER YOUR NAME";

    const std::string BRIEF_BUTTON_TEXT = "BRIEF";

    const std::string MAP_AREA_1_TEXT = "WESTERN EUROPE";
    const std::string MAP_AREA_2_TEXT = "FAR EAST";
    const std::string MAP_AREA_3_TEXT = "MONGOLIA";
    const std::string MAP_AREA_4_TEXT = "IRAN";
    const std::string MAP_AREA_5_TEXT = "CALIFORNIA";
    const std::string MAP_AREA_6_TEXT = "IRAQ";
    const std::string MAP_AREA_7_TEXT = "INDIA";
    const std::string MAP_AREA_8_TEXT = "NORTHEAST TERRITORY";
    const std::string MAP_AREA_9_TEXT = "EASTERN EUROPE";
    const std::string MAP_AREA_10_TEXT = "WESTERN AUSTRALIA";
    const std::string MAP_AREA_11_TEXT = "KAMCHATKA";
    const std::string MAP_AREA_12_TEXT = "MOZAMBIQUE";
    const std::string MAP_AREA_13_TEXT = "CENTRAL EUROPE";
    const std::string MAP_AREA_14_TEXT = "GREENLAND";
    const std::string MAP_AREA_15_TEXT = "PERU";
    const std::string MAP_AREA_16_TEXT = "VENEZUELA";
    const std::string MAP_AREA_17_TEXT = "SCANDINAVIA";
    const std::string MAP_AREA_18_TEXT = "NORTHERN TERRITORIES";
    const std::string MAP_AREA_19_TEXT = "ALASKA";
    const std::string MAP_AREA_20_TEXT = "URALS";
    const std::string MAP_AREA_21_TEXT = "YUKON";
    const std::string MAP_AREA_22_TEXT = "NEW ENGLAND";
    const std::string MAP_AREA_23_TEXT = "SIBERIA";
    const std::string MAP_AREA_24_TEXT = "LYBIA";
    const std::string MAP_AREA_25_TEXT = "URUGUAY";
    const std::string MAP_AREA_26_TEXT = "PACIFIC RIM";
    const std::string MAP_AREA_27_TEXT = "PARAGUAY";
    const std::string MAP_AREA_28_TEXT = "CHINA";
    const std::string MAP_AREA_29_TEXT = "ATLANTIC ACCELERATOR";
    const std::string MAP_AREA_30_TEXT = "ARABIA";
    const std::string MAP_AREA_31_TEXT = "NORTHWEST TERRITORIES";
    const std::string MAP_AREA_32_TEXT = "COLORADO";
    const std::string MAP_AREA_33_TEXT = "SUDAN";
    const std::string MAP_AREA_34_TEXT = "MID WEST";
    const std::string MAP_AREA_35_TEXT = "KAZAKHSTAN";
    const std::string MAP_AREA_36_TEXT = "KENYA";
    const std::string MAP_AREA_37_TEXT = "MAURITANIA";
    const std::string MAP_AREA_38_TEXT = "NEW SOUTH WALES";
    const std::string MAP_AREA_39_TEXT = "NEWFOUNDLANDS";
    const std::string MAP_AREA_40_TEXT = "ARGENTINA";
    const std::string MAP_AREA_41_TEXT = "SOUTHERN STATES";
    const std::string MAP_AREA_42_TEXT = "ZAIRE";
    const std::string MAP_AREA_43_TEXT = "ALGERIA";
    const std::string MAP_AREA_44_TEXT = "COLOMBIA";
    const std::string MAP_AREA_45_TEXT = "NIGERIA";
    const std::string MAP_AREA_46_TEXT = "BRAZIL";
    const std::string MAP_AREA_47_TEXT = "ROCKIES";
    const std::string MAP_AREA_48_TEXT = "INDONESIA";
    const std::string MAP_AREA_49_TEXT = "MEXICO";
    const std::string MAP_AREA_50_TEXT = "SOUTH AFRICA";

    const std::string MISSION_1_TITLE_TEXT = "MERCENARY CAMP";
    const std::string MISSION_2_TITLE_TEXT = "THE MILK RUN";
    const std::string MISSION_3_TITLE_TEXT = "URBAN ASSAULT";
    const std::string MISSION_4_TITLE_TEXT = "RAIDERS";
    const std::string MISSION_5_TITLE_TEXT = "CLEAN SWEEP";
    const std::string MISSION_6_TITLE_TEXT = "SCUM PATROL";
    const std::string MISSION_6_2_TITLE_TEXT = "SNATCH AND GRAB";
    const std::string MISSION_6_3_TITLE_TEXT = "SPRING CLEANING";

    const std::string ATLANTIC_ACCELERATOR_TEXT = "ATLANTIC ACCELERATOR";
    const std::string POP_TEXT = "POP";
    const std::string TAX_TEXT = "TAX";
    const std::string OWN_TEXT = "OWN";
    const std::string UNKNOWN_TEXT = "UNKNOWN";

    const std::string MAP_BUTTON_TEXT = "MAP";

    const std::string ENHANCE_TEXT = "ENHANCE";
    const std::string INFO_TEXT = "INFO";

    const std::string MISSION_BRIEF_TEXT = "MISSION BRIEF";

    const std::string MISSION_1_TEXT = "Mercenary Camp.Assassination. Intelligence reports have indicated that an army colonel is stealing resources from your weapons division and using them to equip his mercenaries. His base has been set up just outside one of our citires and the populace have reported disturbances caused by his troops. Your squad will be deployed near the entrace to the camp. Their objective is to eliminate the colonel. Defence update: Surveillance reports show that the camp is guarded by about five militia armed with both shotguns and pistols. Target update: The colonel is believed to stay in the northern most building of the camp. If he becomes aware of your presence he may decide to withdraw. He must not be allowed to escape. Tactics: A single agent could infiltrate the camp and assassinate the target quite easily. It is important to note that whilst a shotgun is devastating as a close in weapon it is seriously outranged by the pistol and so provision should be made for both of these weapons to be used to their best potential. It is also advised that a similarly equipped agent be kept outside the camp for backup if needed.";
    const std::string MISSION_2_TEXT = "The Milk Run. Personnel aquisition. Two notable scientists are both staying in a small hamlet close to one of our research complexes. They would obviously be a great help to our R and D boys. Your squad has instructions to <persuade> both the scientists to join our reputable organisation. City update: There is a sewer system that runs from the research complex to the river and it has inlets in the hamlet itself. Your squad will be transported by sewer raft to a drop off point in the town itself. The sewers are very dangerous however and without the proper equipment it is inadvisable to enter them. Defence update: There is a very small police presence in the town that should provide no problem at all. One of the scientists however has brought along a bodyguard. These have to be eliminated carefully so as to not damage the target. Tactics: Small arms are all that is really necessary for this mission. Do not use shotguns for dealing with the bodyguards or anyone who happens to be close to the target. Only one agent is required although you may want to take in another as backup. ";
    const std::string MISSION_3_TEXT = "Urban Assault. Combat sweep. A small town is holding out against all our advertising campaigns thanks to enemy syndicate influence. This is having a detrimental effect on our profits and so we have decided to step up the campaign. An assault squad should enter the town and eliminate all enemy syndicate activity in the area. This will leave the town open for our marketing boys. City update: The town is very small and the main entrance is only accessable by vehicle. The transport division has provided a ground car for this mission. Please try to bring it back. Defence update: There is little or no police influence in the town and the enemy syndicate forces are seriously under strength. Now is the ideal time to strike. Tactics: A well equipped squad should have no problems with this one. Stick together and the enemy squad should fall before you. Shotguns and a few medikits just in case are all that is really needed. ";
    const std::string MISSION_4_TEXT = " Raiders. Assassination. An enemy syndicate has brainwashed a notable scientist who now works for them. He has improved their equipment a tremendous amount and is a serious asset. Unfortunately they have inserted a small chip in his brain which detects the activity of the persuadertron and blocks the signal making him immune to <persuasion>. He cannot be allowed to continue his research for the enemy and so he must be eliminated. City update: The city is quite small and relatively undefended. A small squad should have no problems in reaching the installation in the south west sector and achieving the mission objective. Tactics: Resistance is expected to be quite light so heavy weapons will not be needed. Indeed it would be risky allowing such technology to possibly fall into enemy hands. Proceed with all speed to the installation ignoring all other aspects of the city. Keep it tight and you should have no problems. ";
    const std::string MISSION_5_TEXT = " Clean Sweep. Combat sweep. An enemy syndicate has been experiencing problems with the population of a nearby city. This is mainly due to subversive techniques from our espionage department. As a result of this the enemy syndicate has pulled out most of its forces from the surrounding area and the city has fallen open for us to take. Your squad is to conduct a reconnaissance sweep of the area to clear out any enemy syndicate agents remaining inside city limits before returning to the pick up point. Syndicate update: The enemy squad is seriously under strength and poorly equipped. The police force is almost non existant and shouldnt provide any more problem for you than it does for them. Tactics: Small arms with automatics for support are all that are really needed for this mission. A squad of two agents could cover the city in almost no time at all. Either keep both agents tight to each other and concentrate firepower on individual targets or drag one agent further behind with longer ranged equipment to provide cover for the first. ";
    const std::string MISSION_6_TEXT = " Scum Patrol. Combat sweep. A nearby city has just fallen into anarchy, with the untimely death of the mayor. Even though this was nothing to do with us, we feel that the good citizens of the city require our support and understanding at this terrible time. Other syndicates also seem to have the same idea however. Your squad is to peform a sweep through the city, to clear out any of the enemy syndicate slime. Syndicate update: At least three enemy squads have been sighted in the area. With any luck, they will all be gunning for each other as well, so you won't have much to worry about them. Tactics: Let them fight it out amongst themselves. Keep your squad together and just try to avoid getting caught in the crossfire. Bide your time and just defend yourselves until most of the enemy has died, before mopping up the rest of the opposition. Automatics with a few long range support weapons are called for in this one. As it could be a long mission, you would be well advised to take a few medikits as well. ";
    const std::string MISSION_7_TEXT = " Snatch and Grab. Personnel aquisition. The notable professor valken is attending a conference in the research labs of a nearby city. He is believed to be the worlds leading authority on cybernetics and so would make an ideal ally for our research and design department. The research labs are in a seperate complex in the southern sector of the city. Your squad will be deployed in a cooperative chemical plant to the north. Their mission is to <persuade> the professor to join us. Once he has been persuaded, a drop ship will come to pick up the squad. Ensure that all agents are within the pick up zone. City update: The city itself is split into two distinct levels. The lower ground level is a slum whilst the upper apartments are quite plush. A monorail runs through the middle of the city and it is believed to be quite reliable. Target update: Reports seem to indicate that the research complex is only accessable from the higher street level so finding a way up to the walkways is a very high priority. Tactics: A small squad will attract less attention to itself that a larger one. Shotguns should be adequate for dealing with the slums, but when you enter the research complex we cant have any firing in there. ";
    const std::string MISSION_8_TEXT = " Spring Cleaning. Combat sweep. An up and coming town has just attracted the attention of head office as being a very promising base for our marketing boys to experiment with. It is occupied and defended by several syndicate squads and obviously we cannot move in until they are removed. Your squad must sweep through the city and wipe out all trace of the enemy scum. City update: The city itself is divided in two by a rail line. The only way to cross between the two is by a shuttle train that is very quick and efficient. Syndicate update: The latest reports seem to indicate that there are at least three enemy defence squads. We also believe that their spy network knows that we are coming. They will therefore be ready for you and you should expect stiff resistance. Tactics: The full squad should be deployed for this one. One or two of the agents should be equipped with support weaponry and drag behind the others when they move. This will allow them to provide cover fire for the front line men. Try to clear the first side of agents before moving the whole squad over to the other side. Do not split your squad between the two halves as they will then be easy pickings for the enemy. ";

    const std::string TEAM_SELECTION_TEXT = "TEAM SELECTION";
    const std::string RESEARCH_BUTTON_TEXT = "RESEARCH";
    const std::string TEAM_BUTTON_TEXT = "TEAM";
    const std::string MODS_BUTTON_TEXT = "MODS";
    const std::string EQUIP_BUTTON_TEXT = "EQUIP";
    const std::string ITEM_1_TEXT = "PERSUADERTRON";
    const std::string ITEM_2_TEXT = "PISTOL";
    const std::string ITEM_3_TEXT = "SHOTGUN";
    const std::string ITEM_4_TEXT = "SCANNER";
    const std::string ITEM_5_TEXT = "MEDIKIT";
    const std::string ITEM_6_TEXT = "COST";
    const std::string ITEM_7_TEXT = "AMMO";
    const std::string EQUIPMENT_1_TEXT = "ACCESS CARD";
    const std::string EQUIPMENT_2_TEXT = "AIR RAID COM";
    const std::string EQUIPMENT_3_TEXT = "CLONE SHIELD";
    const std::string EQUIPMENT_4_TEXT = "ENERGY SHIELD";
    const std::string EQUIPMENT_5_TEXT = "FLAMER";
    const std::string EQUIPMENT_6_TEXT = "GAUS GUN";
    const std::string EQUIPMENT_7_TEXT = "MEDIKIT";
    const std::string EQUIPMENT_8_TEXT = "LASER";
    const std::string EQUIPMENT_9_TEXT = "LONG RANGE";
    const std::string EQUIPMENT_10_TEXT = "MINI-GUN";
    const std::string EQUIPMENT_11_TEXT = "PERSUADERTRON";
    const std::string EQUIPMENT_12_TEXT = "PISTOL";
    const std::string EQUIPMENT_13_TEXT = "SCANNER";
    const std::string EQUIPMENT_14_TEXT = "SHOTGUN";
    const std::string EQUIPMENT_15_TEXT = "TIME BOMB";
    const std::string EQUIPMENT_16_TEXT = "UZI";

    struct AgentModel
    {
        int InventorySlot[8];
    } Agent[4];

    struct WeaponModel
    {
        std::string Title;
        int value;
        int ammo;
        int range;
        int shot;
        std::string Description;
    } Weapon[13];

    struct ModsModel
    {
        std::string Title;
        int value;
        std::string Description;
    } Mod[20];

    struct MapModel
    {
        std::string Title;
        int Population;
        int Tax;
        int TaxPercentage;
        int Stat; // Unknown, Very happy, happy, unhappy
        SDL_Rect Box;
    } MapArea[49];

    struct CompanyModel
    {
        int Cash;
    } Company;

    struct ResearchModel
    {
        int AssignedFunding;
        //Max dev days 10
        // 0-100%
    };

    const std::string RANGE_STAT_TEXT = "RANGE";
    const std::string SHOT_STAT_TEXT = "SHOT";
    const std::string PURCHASE_BUTTON_TEXT = "PURCHASE";

    const std::string RESEARCH_TEXT = "RESEARCH";

    const std::string AUTOMATIC_BUTTON_TEXT = "AUTOMATIC";
    const std::string HEAVY_BUTTON_TEXT = "HEAVY";
    const std::string ASSAULT_BUTTON_TEXT = "ASSAULT";
    const std::string MISCELLANEOUS_BUTTON_TEXT = "MISCELLANEOUS";

    const std::string MIN_FUNDING_TEXT = "MIN FUNDING";
    const std::string MAX_FUNDING_TEXT = "MAX FUNDING";
    const std::string FUNDING_PLUS_BUTTON_TEXT = "FUNDING+";
    const std::string FUNDING_MINUS_BUTTON_TEXT = "FUNDING-";

    const std::string LOADING_GAME_TEXT = "LOADING GAME";
    const std::string ASSASSINATE_TEXT = "ASSASSINATE";
    const std::string GOING_TEXT = "GOING";
    const std::string FOLLOW_TEXT = "FOLLOW";
    const std::string HIT_BY_A_BULLET_TEXT = "HIT BY A BULLET";

    const std::string MISSION_FAILED_TEXT = "MISSION FAILED";

    const std::string MISSION_DEBRIEFING_TEXT = "MISSION DEBRIEFING";
    const std::string MISSION_STATISTICS_TEXT = "MISSION STATISTICS";
    const std::string MISSION_STATUS_TEXT = "MISSION STATUS:";
    const std::string AGENT_USED_TEXT = "AGENT USED:";
    const std::string NEW_AGENT_GAINED_TEXT = "NEW AGENT GAINED:";
    const std::string TIME_IN_MISSION_TEXT = "TIME IN MISSION";
    const std::string ENEMY_AGENT_KILLED_TEXT = "ENEMY AGENTS KILLED:";
    const std::string CRIMINALS_KILLED_TEXT = "CRIMINALS KILLED:";
    const std::string CIVILIANS_KILLED_TEXT = "CIVILIANS KILLED:";
    const std::string POLICE_KILLED_TEXT = "POLICE KILLED:";
    const std::string GUARDS_KILLED_TEXT = "GUARDS KILLED:";
    const std::string PEOPLE_PERSUADED_TEXT = "PEOPLE PERSUADED:";
    const std::string HIT_ACCURACY_TEXT = "HIT ACCURACY:";

    const std::string DARK_RED_TEXT = "DARK RED";
    const std::string LIGHT_RED_TEXT = "LIGHT RED";
    const std::string WHITE_TEXT = "WHITE";
    const std::string BLUE_TEXT = "BLUE";
    const std::string YELLOW_TEXT = "YELLOW";
    const std::string BEIGE_TEXT = "BEIGE";
    const std::string BROWN_TEXT = "BROWN";
    const std::string DARK_BLUE_TEXT = "DARK BLUE";

    const std::string RELOAD_TEXT = "RELOAD";

    bool CONFIGURE_COMPANY_BUTTON_PRESSED = false;
    bool BEGIN_MISSION_BUTTON_PRESSED = false;
    bool LOAD_AND_SAVE_GAME_BUTTON_PRESSED = false;
    bool RESTART_GAME_BUTTON_PRESSED = false;

    bool CONFIGURE_COMPANY_SCENE = false;
    bool BEGIN_MISSION_SCENE = false;
    bool LOAD_AND_SAVE_GAME_SCENE = false;
    bool RESTART_GAME_SCENE = false;


    const SDL_Rect MAIN_MENU_RECT = {0,0,0,0};
    SDL_Surface* MAIN_MENU_SURFACE;
    const std::string MAIN_MENU_SURFACE_IMAGE = "syndicate/main_menu.bmp";
    std::map<char,int> first;

    struct A{
        static std::map<int,SDL_Rect> create_map()
            {
              std::map<int,SDL_Rect> m;
              //x,y,w,h
              m[0] = {475,270,970,150};
              m[1] = {475,460,970,150};
              m[2] = {475,650,970,150};
              m[3] = {475,860,970,150};
              m[4] = {1250,150+128,128,128};
              m[5] = {1250,150,128,128};
              m[6] = {1350,150+128,128,128};
              m[7] = {1350,150,128,128};
              //m[1] = 2;
              //m[3] = 4;
              //m[5] = 6;
              return m;
            }
        static const std::map<int,SDL_Rect> myMap;

    };

    const std::map<int,SDL_Rect> A::myMap =  A::create_map();

  //MODS

  //General Comments: In general all the mods of one type do the same thing,
  //but progressively better as the version increases.

  const std::string MOD_1_TEXT = "Legs V1";
  const int MOD_1_PRICE = 12000;
  const std::string MOD_1_DESCRIPTION = "Servo Assisted Hydraulics Allow quicker movement.";

  const std::string MOD_2_TEXT = "Legs V2";
  const int MOD_2_PRICE = 16000;
  const std::string MOD_2_DESCRIPTION = "Plasteel legs.  Lighter and tougher than metal. Enhanced Hydraulics and balance control.";

  const std::string MOD_3_TEXT = "Legs V3";
  const int MOD_3_PRICE = 26000;
  const std::string MOD_3_DESCRIPTION = "Cybermesh legs, plasteel core with synthetic muscle fibre. Superb response and balance coupled with speed.";

  //Comments: Make you walk faster.  Quite useful if no car is available.

  const std::string MOD_4_TEXT = "Arms V1";
  const int MOD_4_PRICE = 9000;
  const std::string MOD_4_DESCRIPTION = "Servo Assisted Hydraulics Allow carrying heavier items.";

  const std::string MOD_5_TEXT = "Arms V2";
  const int MOD_5_PRICE = 16000;
  const std::string MOD_5_DESCRIPTION = "Plasteel arms.  Lighter and tougher than metal. Enhanced Hydraulics system and pressure control.";

  const std::string MOD_6_TEXT = "Arms V3";
  const int MOD_6_PRICE = 26000;
  const std::string MOD_6_DESCRIPTION = "Cybermesh legs, plasteel core with synthetic muscle fibre. Excellent tactile control and weight loading.";

  //Comments: Arms allow you to carry heavy guns without walking slower.

  const std::string MOD_7_TEXT = "Chest V1";
  const int MOD_7_PRICE = 18000;
  const std::string MOD_7_DESCRIPTION = "Metal Chest Cage. All internal organs are shielded by heavy metal casting.";

  const std::string MOD_8_TEXT = "Chest V2";
  const int MOD_8_PRICE = 21000;
  const std::string MOD_8_DESCRIPTION = "Plasteel Chest Cage. Lighter and tougher than metal version, with better mobility.";

  const std::string MOD_9_TEXT = "Chest V3";
  const int MOD_9_PRICE = 25000;
  const std::string MOD_9_DESCRIPTION = "Cybermesh Chest Cage with Power Shielding. All organs are shielded by a low power field generator.";

  //Comments: Decrease damage taken from enemy bullets.  Regenerate damage.

  const std::string MOD_10_TEXT = "Brain V1";
  const int MOD_10_PRICE = 10000;
  const std::string MOD_10_DESCRIPTION = "Neural Enhancer. Speeds up brain stem response time.";

  const std::string MOD_11_TEXT = "Brain V2";
  const int MOD_11_PRICE = 14000;
  const std::string MOD_11_DESCRIPTION = "Neuro CNS Device. Intercepts most low level functions leaving the brain for high end decisions.";

  const std::string MOD_12_TEXT = "Brain V3";
  const int MOD_12_PRICE = 18000;
  const std::string MOD_12_DESCRIPTION = "Cerebral Multiplier. Connected to compnet gives access to a mass of tactical info. Adapted from the military version.";

  //Comments:  Longer sustenance of the intelligence hormone.

  const std::string MOD_13_TEXT = "Heart V1";
  const int MOD_13_PRICE = 6000;
  const std::string MOD_13_DESCRIPTION = "Heart Stimulator. Monitor and mantains the heart rate of an individual.";

  const std::string MOD_14_TEXT = "Heart V2";
  const int MOD_14_PRICE = 8000;
  const std::string MOD_14_DESCRIPTION = "Heart Accelerator and Monitor. Heart rate is almost doubled allowing quicker distribution of hormones.";

  const std::string MOD_15_TEXT = "Heart V3";
  const int MOD_15_PRICE = 11000;
  const std::string MOD_15_DESCRIPTION = "Cybernetic Heart. Powerful pump with built in system analysis and override facilities. Triples output of a standart human heart.";

  //Comments:  Longer sustenance of the adrenaline hormone.

  const std::string MOD_16_TEXT = "Eyes V1";
  const int MOD_16_PRICE = 4000;
  const std::string MOD_16_DESCRIPTION = "Vision Enhancer with limited zoom capability. Allows near perfect vision even at night.";

  const std::string MOD_17_TEXT = "Eyes V2";
  const int MOD_17_PRICE = 4000;
  const std::string MOD_17_DESCRIPTION = "Enhanced model of V1 incorporating target acquisition and range finder.";

  const std::string MOD_18_TEXT = "Eyes V3";
  const int MOD_18_PRICE = 4000;
  const std::string MOD_18_DESCRIPTION = "Latest neurocybernetic implants, give totally perfect night vision with targeters, range finders and threat identifiers.";

  //Comments:  Longer sustenance of the perception hormone.

  //WEAPONS:

  //General Comments:
  //Cost-how much it costs to produce and sell
  //Ammo-how many bullets it holds
  //Range- how far will it shoot
  //Shot-how many bullets it shoots at one time

  const std::string WEAPON_1_TEXT = "Persuadertron";
  const int WEAPON_1_COST = 5000;
  const int WEAPON_1_AMMO = 50;
  const int WEAPON_1_RANGE = 256;
  const int WEAPON_1_SHOT = 10;

//  Comments: Useless as a killing weapon, but needed to <PERSUADE> people
//  in certain missions.

    const std::string WEAPON_2_TEXT = "Pistol";
    const int WEAPON_2_COST = 100;
    const int WEAPON_2_AMMO = 13;
    const int WEAPON_2_RANGE = 1200;
    const int WEAPON_2_SHOT = 1;

//  Comments: Not very good.  Buy a shotgun instead at the early stages.

    const std::string WEAPON_3_TEXT = "Gaus Gun";
    const int WEAPON_3_COST = 50000;
    const int WEAPON_3_AMMO = 3;
    const int WEAPON_3_RANGE = 5120;
    const int WEAPON_3_SHOT = 15000;

//  Comments: Very powerful.  Fires a stream of bullets, but little ammo
//  and unnecessary.

    const std::string WEAPON_4_TEXT = "Shot Gun";
    const int WEAPON_4_COST = 250;
    const int WEAPON_4_AMMO = 12;
    const int WEAPON_4_RANGE = 1024;
    const int WEAPON_4_SHOT = 2;

//  Comments: The weapon of choice for the early stages.

    const std::string WEAPON_5_TEXT = "Uzi";
    const int WEAPON_5_COST = 750;
    const int WEAPON_5_AMMO = 50;
    const int WEAPON_5_RANGE = 1792;
    const int WEAPON_5_SHOT = 2;

//  Comments: Good for long range weapon in early stages.

    const std::string WEAPON_6_TEXT = "Mini Gun";
    const int WEAPON_6_COST = 10000;
    const int WEAPON_6_AMMO = 2000;
    const int WEAPON_6_RANGE = 2304;
    const int WEAPON_6_SHOT = 2;

//  Comments: The best all around weapon.  Unbeatable value and firepower.

    const std::string WEAPON_7_TEXT = "Laser";
    const int WEAPON_7_COST = 35000;
    const int WEAPON_7_AMMO = 5;
    const int WEAPON_7_RANGE = 4096;
    const int WEAPON_7_SHOT = 2000;

//  Comments: Kills outright if hits.  Little ammo.  Expensive.

    const std::string WEAPON_8_TEXT = "Flamer";
    const int WEAPON_8_COST = 1500;
    const int WEAPON_8_AMMO = 1000;
    const int WEAPON_8_RANGE = 640;
    const int WEAPON_8_SHOT = 1;

//  Comments: Good for toasting enemy syndicate agents.  Great for missions
//  requiring elimination of a large number of enemy syndicates, as it
//  kills outright if hits.

    const std::string WEAPON_9_TEXT = "Long Range";
    const int WEAPON_9_COST = 1000;
    const int WEAPON_9_AMMO = 30;
    const int WEAPON_9_RANGE = 3584;
    const int WEAPON_9_SHOT = 2;

//  Comments: Good for long range sniping, but weak.

    const std::string WEAPON_10_TEXT = "Scanner";
    const int WEAPON_10_COST = 500;
    const int WEAPON_10_AMMO = 1;
    const int WEAPON_10_RANGE = 256;
    const int WEAPON_10_SHOT = 1;

//  Comments: Allows you to increase the range of your radar without paying
//  for it in every mission.  Must be carried to work.

    const std::string WEAPON_11_TEXT = "Medi Kit";
    const int WEAPON_11_COST = 3000;
    const int WEAPON_11_AMMO = 1;
    const int WEAPON_11_RANGE = 256;
    const int WEAPON_11_SHOT = 500;

//  Comments: Restores energy of your Cyborg.

    const std::string WEAPON_12_TEXT = "Time Bomb";
    const int WEAPON_12_COST = 25000;
    const int WEAPON_12_AMMO = 200;
    const int WEAPON_12_RANGE = 256;
    const int WEAPON_12_SHOT = 1;

//  Comments: After dropping it, it will produce a *large* explosion.

    const std::string WEAPON_13_TEXT = "Access Card";
    const int WEAPON_13_COST = 1000;
    const int WEAPON_13_AMMO = 1;
    const int WEAPON_13_RANGE = 256;
    const int WEAPON_13_SHOT = 1;

    const std::string WEAPON_14_TEXT = "energy Shield";
    const int WEAPON_14_COST = 8000;
    const int WEAPON_14_AMMO = 200;
    const int WEAPON_14_RANGE = 768;
    const int WEAPON_14_SHOT = 15;

//  Comments: Protects from bullets only.  Has to be equipped to work.

    int DEFAULT_TAX_PERCENTAGE = 30;
    int Areas[49];
    std::string factions[7];
    SDL_Rect BRIEF_BUTTON;
    SDL_Rect MENU_BUTTON;
    SDL_Rect SAVE_GAME_BUTTON[10];
};
//Total windows
const int TOTAL_WINDOWS = 3;
class LWindow
{
public:
//Intializes internals
LWindow(){};
//Creates window
bool init();
//Handles window events
void handleEvent( SDL_Event& e );
//Focuses on window
void focus();
//Shows windows contents
void render();
//Deallocates internals
void free();
//Window dimensions
int getWidth(); int getHeight();
//Window focii
bool hasMouseFocus();
bool hasKeyboardFocus();
bool isMinimized();
bool isShown();
private:
//Window data
SDL_Window* mWindow;
SDL_Renderer* mRenderer;
int mWindowID;
//Window dimensions
int mWidth;
int mHeight;
//Window focus
bool mMouseFocus;
bool mKeyboardFocus;
bool mFullScreen;
bool mMinimized;
bool mShown;
};

//Our custom windows
LWindow gWindows[ TOTAL_WINDOWS ];

int FullScreen(SDL_Window* window, Uint32 flags)
{
    return SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}


bool LWindow::init()
{
    //Create window
    mWindow = SDL_CreateWindow( WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    /*
    if ( FullScreen(mWindow,SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
    {
        std::cout << SDL_GetError() << std::endl;
        exit (0);
    }
    else
    {
        std::cout << "Changing to Fullscreen" << std::endl;
        exit(0);
    }
    */

    if( mWindow != NULL )
    {
        mMouseFocus = true;
        mKeyboardFocus = true;
        mWidth = SCREEN_WIDTH;
        mHeight = SCREEN_HEIGHT;
        //Create renderer for window
        mRenderer = SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ); if( mRenderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            SDL_DestroyWindow( mWindow );
            mWindow = NULL;
        }
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            //Grab window identifier
            mWindowID = SDL_GetWindowID( mWindow );
            //Flag as opened
            mShown = true;
        }
    }
    else
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    }
    return mWindow != NULL && mRenderer != NULL;
}

/* The window */
//SDL_Window* window = NULL;

/* The window surface */
//SDL_Surface* screen = NULL;

/* The event structure */
SDL_Event event;

/* The game loop flag */
_Bool running = true;

/* to put the loaded image */
SDL_Surface* image = NULL;


#ifdef __cplusplus__

  #include <iostream>
  #include <string>

  void ClearScreen()
    {
    cout << string( 100, '\n' );
    }

#else

  #include <stdio.h>

  void ClearScreen()
    {
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

#endif

void font_printer(std::string text, int text_size, int ix, int iy)
{
    int w,h;

    SDL_Color color={0,255,0};
    SDL_Surface *text_surface;

    TTF_Font * font = TTF_OpenFont("/usr/share/fonts/truetype/droid/DroidSans.ttf",text_size);

    //SDL_Color White = {255, 255, 255};

    if (font == NULL)
    {
        std::cout << "NO font guys!" << std::endl;
        exit(1);
    }

    if(!(text_surface=TTF_RenderText_Solid(font,text.c_str(),color)))
    {
        std::cout << "Hey we got a error ehere" << std::endl;
        exit(1);
        //handle error here, perhaps print TTF_GetError at least
    }
    else
    {
        SDL_Rect box;
        box.h = h;
        box.w = w;
        box.x = ix;
        box.y = iy;

        SDL_BlitSurface(text_surface,NULL,screenSurface,&box);
        //perhaps we can reuse it, but I assume not for simplicity.
        //SDL_FreeSurface(text_surface);
    }

    TTF_CloseFont(font);
    SDL_FreeSurface(text_surface);
};

void print_party_information()
{
    std::cout << "Here is the party information" << std::endl;
    std::cout << "Name\t\tHits\t\tSpells\t\tStatus\t\tOption" << std::endl;
    std::cout << "Caretaker\t12/12\t\t120\t\tOk\t\tNone" << std::endl;
}

   #define TILESIZE 32
    #define ROWS 15
    #define COLUMNS 40
    #define PLAYER_W 10
    #define PLAYER_H 10

int playfield[ROWS][COLUMNS] =
{
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,0,0,1,1,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
  0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
  1,1,0,1,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,
  0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
  1,0,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,
  1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
  0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,
  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

int t, tl = 0, frequency = 1000 / 100, temp, t2; //StopBall variables

    struct _Player
    {
        int w, h, onGround;
        int x, y, jump, lockjump;
        float dirX, dirY;
    } Player;

        struct _Game{
       int mapx;
   } Game;

   struct _Camera
   {
      int x, y;
   } Camera;


    void DrawRect(int x, int y, int width, int height, int color)
    {
            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            rect.w = width;
            rect.h = height;
            SDL_FillRect(screen, &rect, color);
    }

   void drawbackground()
    {
       int i;
       int j;
       int row = Camera.y / TILESIZE;
       int column = Camera.x / TILESIZE;
       int shiftX = Camera.x % TILESIZE;
       int shiftY = Camera.y % TILESIZE;

       for (i = 0; i < ROWS; i ++)
        {
           for (j = 0; j < COLUMNS; j ++)
           {
             if(playfield[row + i][column + j]==0)
                 DrawRect(j * TILESIZE - shiftX, i * TILESIZE - shiftY, TILESIZE, TILESIZE, 0xf0f0ff);
           }
        }
    }

    void Draw()
    {
       drawbackground();
       DrawRect(Player.x - Camera.x + (SCREEN_WIDTH/2), Player.y - Camera.y + (SCREEN_HEIGHT/2), PLAYER_W, PLAYER_H, 0xff0000);
       DrawRect(Player.x, Player.y, PLAYER_W, PLAYER_H, 0xff0000);
       //printf("Player.x %d Camera.x %d X %d\n", (int)Player.x, (int)Camera.x, (int)Player.x - (int)Camera.x + (SCREEN_WIDTH/2));
       //printf("Player.y %d Camera.y %d Y %d\n", (int)Player.y, (int)Camera.y, (int)Player.y - (int)Camera.y + (SCREEN_WIDTH/2));
       DrawRect(Camera.x, Camera.y, PLAYER_W, PLAYER_H, 0x00ff00);
    }

        int fps_sync ()
    {
        t = SDL_GetTicks ();
        printf("tl: %d t: %d\n", tl, t);
        if (t - tl >= frequency)
        {
            temp = (t - tl) / frequency; //delta time
            tl += temp * frequency;
            printf("temp: %d tl: %d \n", t, tl);
            return temp;
        }
        else
        {
            SDL_Delay (frequency - (t - tl));
            tl += frequency;
            return 1;
        }
    }

    void doCamera()
    {
       //Converte da coordinata a tiles???
       int limitX = COLUMNS * TILESIZE - SCREEN_WIDTH;
       int limitY = ROWS * TILESIZE - SCREEN_HEIGHT;

       /* se acerca a la posición del tanque de manera gradual */
       Camera.x +=  Player.x - Camera.x;
       Camera.y +=  Player.y - Camera.y;

       /* detiene el desplazamiento en los límites */
       if (Camera.x < 0)
        Camera.x = 0;

       if (Camera.y < 0)
        Camera.y = 0;

       if (Camera.x > limitX)
        Camera.x = limitX;

       if (Camera.y > limitY)
        Camera.y = limitY;
    }
Uint8 *keystate; // keyboard state

class Window_SDL2
{
    public:
    private:
    Window_SDL2(){};
    ~Window_SDL2(){};
};

int FullScreenGlobal(SDL_Window* window, Uint32 flags)
{
    return SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);// SDL_WINDOW_FULLSCREEN_DESKTOP
}

std::string intToString(int i)
{
    std::stringstream ss;
    std::string s;
    ss << i;
    s = ss.str();

    return s;
}

void ConfigureCompany()
{
    SDL_Surface* LOGO_SURFACE;
    SDL_Surface* ARROW_LEFT_SURFACE;
    SDL_Surface* ARROW_RIGHT_SURFACE;
    SDL_Surface* BACKGROUND_SURFACE;


    LOGO_SURFACE = SDL_LoadBMP( "bullfrog_productions.bmp" );
    ARROW_LEFT_SURFACE = SDL_LoadBMP( "arrow-left.bmp" );
    ARROW_RIGHT_SURFACE = SDL_LoadBMP( "arrow-right.bmp" );
    BACKGROUND_SURFACE = SDL_LoadBMP( "synd_desktop_render07_hq.bmp" );

    //SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
    SDL_Rect box;
    box.h = 48;
    box.w = 48;
    box.x = 1250;
    box.y = 150;

    SDL_BlitSurface( BACKGROUND_SURFACE, NULL, screenSurface, NULL );

    SDL_FillRect(screenSurface, &A::myMap.at(4), SDL_MapRGB(screenSurface->format, 0, 0, 255));
    SDL_FillRect(screenSurface, &A::myMap.at(5), SDL_MapRGB(screenSurface->format, 0, 0, 255));
    SDL_FillRect(screenSurface, &A::myMap.at(6), SDL_MapRGB(screenSurface->format, 0, 0, 255));
    SDL_FillRect(screenSurface, &A::myMap.at(7), SDL_MapRGB(screenSurface->format, 0, 0, 255));


    SDL_BlitSurface( LOGO_SURFACE, NULL, screenSurface, NULL );
    SDL_BlitSurface( ARROW_LEFT_SURFACE, NULL, screenSurface, &box );
    box.h = 48;
    box.w = 48;
    box.x = 1350;
    box.y = 150;
    SDL_BlitSurface( ARROW_RIGHT_SURFACE, NULL, screenSurface, &box );
    box.h = 48;
    box.w = 48;
    box.x = 1250;
    box.y = 150+128;
    SDL_BlitSurface( ARROW_LEFT_SURFACE, NULL, screenSurface, &box );
    box.h = 48;
    box.w = 48;
    box.x = 1350;
    box.y = 150+128;
    SDL_BlitSurface( ARROW_RIGHT_SURFACE, NULL, screenSurface, &box );

    box.h = 48;
    box.w = 48;
    box.x = 900;
    box.y = 100;

    SDL_BlitSurface( LOGO_SURFACE, NULL, screenSurface, &box );
    font_printer(ACCEPT_BUTTON_TEXT.c_str(),24,0,SCREEN_HEIGHT -100);
    font_printer(MENU_BUTTON_TEXT.c_str(),24,SCREEN_WIDTH -300,SCREEN_HEIGHT-100);
    font_printer(OK_BUTTON_TEXT.c_str(),24,900,530);
    font_printer(CANCEL_BUTTON_TEXT.c_str(),24,1500,530);
    font_printer(COLOR_BUTTON_TEXT.c_str(),24,1500,200);
    font_printer(LOGO_BUTTON_TEXT.c_str(),24,1500,330);
    font_printer(CHANGE_COMPANY_TEXT.c_str(),24,1500,430);

    std::string activated = std::to_string(LOGO_ID_ACTIVE);
    font_printer(activated.c_str(),24,0,0);

//    SDL_Rect box_top_left;
//    box_top_left.h = 48;
//    box_top_left.w = 48;
//    box_top_left.x = 1250;
//    box_top_left.y = 200;
//    SDL_FillRect(screenSurface, &box_top_left, SDL_MapRGB(screenSurface->format, 0, 0, 255));
//
//    SDL_Rect box_top_right;
//    box_top_right.h = 48;
//    box_top_right.w = 48;
//    box_top_right.x = 1300;
//    box_top_right.y = 200;
//    SDL_FillRect(screenSurface, &box_top_right, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//
//    SDL_Rect box_bottom_left;
//    box_bottom_left.h = 48;
//    box_bottom_left.w = 48;
//    box_bottom_left.x = 1250;
//    box_bottom_left.y = 300;
//    SDL_FillRect(screenSurface, &box_bottom_left, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//
//    SDL_Rect box_bottom_right;
//    box_bottom_right.h = 48;
//    box_bottom_right.w = 48;
//    box_bottom_right.x = 1300;
//    box_bottom_right.y = 300;
//    SDL_FillRect(screenSurface, &box_bottom_right, SDL_MapRGB(screenSurface->format, 0, 255, 0));

    bool submenu = false;
    if(submenu)
    {
        SDL_Rect box_color_and_logo;
        box_color_and_logo.h = 48;
        box_color_and_logo.w = 48;
        box_color_and_logo.x = 1250;
        box_color_and_logo.y = 200;
        SDL_FillRect(screenSurface, &box_color_and_logo, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_Rect box_company_name;
        box_company_name.h = 48;
        box_company_name.w = 48;
        box_company_name.x = 1250;
        box_company_name.y = 300;
        SDL_FillRect(screenSurface, &box_company_name, SDL_MapRGB(screenSurface->format, 0, 255, 0));

        SDL_Rect box_your_name;
        box_your_name.h = 48;
        box_your_name.w = 48;
        box_your_name.x = 1250;
        box_your_name.y = 400;
        SDL_FillRect(screenSurface, &box_your_name, SDL_MapRGB(screenSurface->format, 0, 255, 0));
    }


    //accept button
    //menu button
    //color and logo button
    //company name button
    //your name button
    //company logo
    //select details to change text
    //company name string printout
    //your name string printout
    // switch sub window
    // left and right buttons
    // ok button
    // cancel button
    // logo image printed
    // exit back to main menu
    SDL_FreeSurface( LOGO_SURFACE );
    SDL_FreeSurface( BACKGROUND_SURFACE );
};
void BeginMission()
{
    // LOADS THE INGAME MAP
};

void InitializeLoadAndSaveGame()
{
        SAVE_GAME_BUTTON[0].h = 48;
        SAVE_GAME_BUTTON[0].w = 150;
        SAVE_GAME_BUTTON[0].x = 1250;
        SAVE_GAME_BUTTON[0].y = 0;

        SAVE_GAME_BUTTON[1].h = 48;
        SAVE_GAME_BUTTON[1].w = 150;
        SAVE_GAME_BUTTON[1].x = 1250;
        SAVE_GAME_BUTTON[1].y = 100;

        SAVE_GAME_BUTTON[2].h = 48;
        SAVE_GAME_BUTTON[2].w = 150;
        SAVE_GAME_BUTTON[2].x = 1250;
        SAVE_GAME_BUTTON[2].y = 200;

        SAVE_GAME_BUTTON[3].h = 48;
        SAVE_GAME_BUTTON[3].w = 150;
        SAVE_GAME_BUTTON[3].x = 1250;
        SAVE_GAME_BUTTON[3].y = 300;

        SAVE_GAME_BUTTON[4].h = 48;
        SAVE_GAME_BUTTON[4].w = 150;
        SAVE_GAME_BUTTON[4].x = 1250;
        SAVE_GAME_BUTTON[4].y = 400;

        SAVE_GAME_BUTTON[5].h = 48;
        SAVE_GAME_BUTTON[5].w = 150;
        SAVE_GAME_BUTTON[5].x = 1250;
        SAVE_GAME_BUTTON[5].y = 500;

        SAVE_GAME_BUTTON[6].h = 48;
        SAVE_GAME_BUTTON[6].w = 150;
        SAVE_GAME_BUTTON[6].x = 1250;
        SAVE_GAME_BUTTON[6].y = 600;

        SAVE_GAME_BUTTON[7].h = 48;
        SAVE_GAME_BUTTON[7].w = 150;
        SAVE_GAME_BUTTON[7].x = 1250;
        SAVE_GAME_BUTTON[7].y = 700;

        SAVE_GAME_BUTTON[8].h = 48;
        SAVE_GAME_BUTTON[8].w = 150;
        SAVE_GAME_BUTTON[8].x = 1250;
        SAVE_GAME_BUTTON[8].y = 800;

        SAVE_GAME_BUTTON[9].h = 48;
        SAVE_GAME_BUTTON[9].w = 150;
        SAVE_GAME_BUTTON[9].x = 1250;
        SAVE_GAME_BUTTON[9].y = 900;

};

void LoadAndSaveGame()
{
    SDL_Surface* MAP_SURFACE;
    int  x,y;

        SDL_FillRect(screenSurface, &BRIEF_BUTTON, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_GetMouseState(&x,&y);
        if(x > BRIEF_BUTTON.x && x < BRIEF_BUTTON.x + BRIEF_BUTTON.w && y > BRIEF_BUTTON.y && y < BRIEF_BUTTON.y + BRIEF_BUTTON.h )
        {
            SDL_FillRect(screenSurface, &BRIEF_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        }
        SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_GetMouseState(&x,&y);
        if(x > MENU_BUTTON.x && x < MENU_BUTTON.x + MENU_BUTTON.w && y > MENU_BUTTON.y && y < MENU_BUTTON.y + MENU_BUTTON.h )
        {
            SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        }

        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[0], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[1], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[2], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[3], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[4], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[5], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[6], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[7], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[8], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[9], SDL_MapRGB(screenSurface->format, 255, 255, 0));
        font_printer("SAVE GAME 1",24,SAVE_GAME_BUTTON[0].x,SAVE_GAME_BUTTON[0].y);
        font_printer("SAVE GAME 2",24,SAVE_GAME_BUTTON[1].x,SAVE_GAME_BUTTON[1].y);
        font_printer("SAVE GAME 3",24,SAVE_GAME_BUTTON[2].x,SAVE_GAME_BUTTON[2].y);
        font_printer("SAVE GAME 4",24,SAVE_GAME_BUTTON[3].x,SAVE_GAME_BUTTON[3].y);
        font_printer("SAVE GAME 5",24,SAVE_GAME_BUTTON[4].x,SAVE_GAME_BUTTON[4].y);
        font_printer("SAVE GAME 6",24,SAVE_GAME_BUTTON[5].x,SAVE_GAME_BUTTON[5].y);
        font_printer("SAVE GAME 7",24,SAVE_GAME_BUTTON[6].x,SAVE_GAME_BUTTON[6].y);
        font_printer("SAVE GAME 8",24,SAVE_GAME_BUTTON[7].x,SAVE_GAME_BUTTON[7].y);
        font_printer("SAVE GAME 9",24,SAVE_GAME_BUTTON[8].x,SAVE_GAME_BUTTON[8].y);
        font_printer("SAVE GAME 10",24,SAVE_GAME_BUTTON[9].x,SAVE_GAME_BUTTON[9].y);


        SDL_Rect load;
        load.h = 48;
        load.w = 150;
        load.x = 0;
        load.y = SCREEN_HEIGHT -100;
        SDL_FillRect(screenSurface, &load, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        SDL_Rect save;
        save.h = 48;
        save.w = 150;
        save.x = 200;
        save.y = SCREEN_HEIGHT -100;
        SDL_FillRect(screenSurface, &save, SDL_MapRGB(screenSurface->format, 0, 255, 0));

        SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));

    // Ten save slots
    // Title EMPTY
    //LOAD AND SAVE BUTTON AND MENU BUTTON
    //TITLE
    //LIST 1-10
    // IN LIST EDITING OF SAVEGAME TITLE
    // SAVE DEFAULTS BACK TO MAIN MENU
};

void MovingInStrightLine()
{
//dx = (double) (Math.cos(angle) * speed);
//dy = (double) (Math.sin(angle) * speed);
//
//A.x += dx;
//A.y += dy;
};

void RestartGame()
{
};

void MissionBriefing()
{
    SDL_Surface* MAP_SURFACE;
    int  x,y;

    MAP_SURFACE = SDL_LoadBMP( "synd_desktop_render07_hq.bmp" );
    //SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
    SDL_Rect box;
    box.h = 48;
    box.w = 48;
    box.x = 0;
    box.y = 0;

    SDL_Rect minimap;
    minimap.h = 200;
    minimap.w = 200;
    minimap.x = SCREEN_WIDTH - 250;
    minimap.y = SCREEN_HEIGHT - 300;

    SDL_Rect info;
    info.h = 32;
    info.w = 200;
    info.x = SCREEN_WIDTH - 250;
    info.y = SCREEN_HEIGHT - 600;

    SDL_Rect enhance;
    enhance.h = 32;
    enhance.w = 200;
    enhance.x = SCREEN_WIDTH - 250;
    enhance.y = SCREEN_HEIGHT - 500;

    SDL_Rect MAP_BUTTON;
    enhance.h = 32;
    enhance.w = 200;
    enhance.x = 200;
    enhance.y = SCREEN_HEIGHT - 100;

    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0, 0, 0 ) );
    SDL_BlitSurface( MAP_SURFACE, NULL, screenSurface, NULL );

    SDL_FillRect( screenSurface, &minimap, SDL_MapRGB( screenSurface->format, 0, 255, 0 ) );
    SDL_FillRect( screenSurface, &info, SDL_MapRGB( screenSurface->format, 0, 255, 0 ) );
    SDL_FillRect( screenSurface, &enhance, SDL_MapRGB( screenSurface->format, 0, 255, 0 ) );
    SDL_FillRect( screenSurface, &MAP_BUTTON, SDL_MapRGB( screenSurface->format, 0, 255, 0 ) );

    SDL_FillRect( screenSurface, &box, SDL_MapRGB( screenSurface->format, 0, 255, 0 ) );


    font_printer(MISSION_1_TEXT.c_str(),12,0,100);

        SDL_FillRect(screenSurface, &BRIEF_BUTTON, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_GetMouseState(&x,&y);
        if(x > BRIEF_BUTTON.x && x < BRIEF_BUTTON.x + BRIEF_BUTTON.w && y > BRIEF_BUTTON.y && y < BRIEF_BUTTON.y + BRIEF_BUTTON.h )
        {
            SDL_FillRect(screenSurface, &BRIEF_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        }
        SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_GetMouseState(&x,&y);
        if(x > MENU_BUTTON.x && x < MENU_BUTTON.x + MENU_BUTTON.w && y > MENU_BUTTON.y && y < MENU_BUTTON.y + MENU_BUTTON.h )
        {
            SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        }
    // Logo in the left top corner
    // title
    // info button and text
    // enhance button and text
    // menu button
    // accept button and map button
    // briefing text
    // time
    // small minimap

};

void TeamSelection()
{
};


void MapAreaCollision(MapModel CheckArea)
{
    bool Collision = false;

    do
    {
        for( int i = 0; i < 49; i++)
        {
            if( Collision )
            {
                Collision = false;
                SDL_Delay(10);
                continue;
            }
            if(CheckArea.Box.x > MapArea[i].Box.x &&
            CheckArea.Box.x < MapArea[i].Box.x + MapArea[i].Box.w ||
            CheckArea.Box.y > MapArea[i].Box.y &&
            CheckArea.Box.y < MapArea[i].Box.y + MapArea[i].Box.h )
            {
                MapArea[i].Box.x += rand()%50;
                MapArea[i].Box.y += rand()%50;
                if( MapArea[i].Box.x + MapArea[i].Box.w > SCREEN_WIDTH )
                    MapArea[i].Box.x = SCREEN_WIDTH;
                if( MapArea[i].Box.y + MapArea[i].Box.h > SCREEN_HEIGHT )
                    MapArea[i].Box.y = SCREEN_HEIGHT;

                Collision = true;
                std::cout << "CheckArea collided with MapArea[" << i << "]" << std::endl;
            }
            else
            {
                MapArea[i].Box.x += 0;
                MapArea[i].Box.y += 0;
                Collision = false;
                std::cout << "CheckArea did not collide with MapArea[" << i << "]" << std::endl;
            }
        }
    } while ( Collision );

};

void InitializeMap()
{
    factions[0] = "Castrilos";
    factions[1] = "EuroCorp";
    factions[2] = "Executive Jihad";
    factions[3] = "IIA";
    factions[4] = "Sphinx";
    factions[5] = "Tao";
    factions[6] = "TLC";

    MapArea[0].Population = 53997325;
    MapArea[0].Stat = 4;
    MapArea[0].Tax = 0;
    MapArea[0].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[0].Title = "Western Europe";
    MapArea[0].Box.h = 48;
    MapArea[0].Box.w = 48;
    MapArea[0].Box.x = rand()%SCREEN_HEIGHT-48;
    MapArea[0].Box.y = rand()%SCREEN_HEIGHT-48;
    MapAreaCollision(MapArea[0]);

    MapArea[1].Population = 53997325;
    MapArea[1].Stat = 4;
    MapArea[1].Tax = 0;
    MapArea[1].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[1].Title = "Central Europe";
    MapArea[1].Box.h = 48;
    MapArea[1].Box.w = 48;
    MapArea[1].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[1].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[1]);

    MapArea[2].Population = 53997325;
    MapArea[2].Stat = 4;
    MapArea[2].Tax = 0;
    MapArea[2].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[2].Title = "Scandinavia";
    MapArea[2].Box.h = 48;
    MapArea[2].Box.w = 48;
    MapArea[2].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[2].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[2]);

    MapArea[3].Population = 53997325;
    MapArea[3].Stat = 4;
    MapArea[3].Tax = 0;
    MapArea[3].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[3].Title = "Algeria";
    MapArea[3].Box.h = 48;
    MapArea[3].Box.w = 48;
    MapArea[3].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[3].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[3]);

    MapArea[4].Population = 53997325;
    MapArea[4].Stat = 4;
    MapArea[4].Tax = 0;
    MapArea[4].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[4].Title = "Urals";
    MapArea[4].Box.h = 48;
    MapArea[4].Box.w = 48;
    MapArea[4].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[4].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[4]);

    MapArea[5].Population = 53997325;
    MapArea[5].Stat = 4;
    MapArea[5].Tax = 0;
    MapArea[5].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[5].Title = "Eastern Europe";
    MapArea[5].Box.h = 48;
    MapArea[5].Box.w = 48;
    MapArea[5].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[5].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[5]);

    MapArea[6].Population = 53997325;
    MapArea[6].Stat = 4;
    MapArea[6].Tax = 0;
    MapArea[6].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[6].Title = "Siberia";
    MapArea[6].Box.h = 48;
    MapArea[6].Box.w = 48;
    MapArea[6].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[6].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[6]);

    MapArea[7].Population = 53997325;
    MapArea[7].Stat = 4;
    MapArea[7].Tax = 0;
    MapArea[7].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[7].Title = "Mongolia";
    MapArea[7].Box.h = 48;
    MapArea[7].Box.w = 48;
    MapArea[7].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[7].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[7]);

    MapArea[8].Population = 53997325;
    MapArea[8].Stat = 4;
    MapArea[8].Tax = 0;
    MapArea[8].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[8].Title = "Kazakhstan";
    MapArea[8].Box.h = 48;
    MapArea[8].Box.w = 48;
    MapArea[8].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[8].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[8]);

    MapArea[9].Population = 53997325;
    MapArea[9].Stat = 4;
    MapArea[9].Tax = 0;
    MapArea[9].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[9].Title = "Kamchatka";
    MapArea[9].Box.h = 48;
    MapArea[9].Box.w = 48;
    MapArea[9].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[9].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[9]);

    MapArea[10].Population = 53997325;
    MapArea[10].Stat = 4;
    MapArea[10].Tax = 0;
    MapArea[10].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[10].Title = "Far East";
    MapArea[10].Box.h = 48;
    MapArea[10].Box.w = 48;
    MapArea[10].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[10].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[10]);

    MapArea[11].Population = 53997325;
    MapArea[11].Stat = 4;
    MapArea[11].Tax = 0;
    MapArea[11].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[11].Title = "China";
    MapArea[11].Box.h = 48;
    MapArea[11].Box.w = 48;
    MapArea[11].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[11].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[11]);

    MapArea[12].Population = 53997325;
    MapArea[12].Stat = 4;
    MapArea[12].Tax = 0;
    MapArea[12].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[12].Title = "Libya";
    MapArea[12].Box.h = 48;
    MapArea[12].Box.w = 48;
    MapArea[12].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[12].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[12]);

    MapArea[13].Population = 53997325;
    MapArea[13].Stat = 4;
    MapArea[13].Tax = 0;
    MapArea[13].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[13].Title = "Iraq";
    MapArea[13].Box.h = 48;
    MapArea[13].Box.w = 48;
    MapArea[13].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[13].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[13]);

    MapArea[14].Population = 53997325;
    MapArea[14].Stat = 4;
    MapArea[14].Tax = 0;
    MapArea[14].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[14].Title = "Iran";
    MapArea[14].Box.h = 48;
    MapArea[14].Box.w = 48;
    MapArea[14].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[14].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[14]);

    MapArea[15].Population = 53997325;
    MapArea[15].Stat = 4;
    MapArea[15].Tax = 0;
    MapArea[15].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[15].Title = "India";
    MapArea[15].Box.h = 48;
    MapArea[15].Box.w = 48;
    MapArea[15].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[15].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[15]);

    MapArea[16].Population = 53997325;
    MapArea[16].Stat = 4;
    MapArea[16].Tax = 0;
    MapArea[16].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[16].Title = "Pacific Rim";
    MapArea[16].Box.h = 48;
    MapArea[16].Box.w = 48;
    MapArea[16].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[16].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[16]);

    MapArea[17].Population = 53997325;
    MapArea[17].Stat = 4;
    MapArea[17].Tax = 0;
    MapArea[17].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[17].Title = "Indonesia";
    MapArea[17].Box.h = 48;
    MapArea[17].Box.w = 48;
    MapArea[17].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[17].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[17]);

    MapArea[18].Population = 53997325;
    MapArea[18].Stat = 4;
    MapArea[18].Tax = 0;
    MapArea[18].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[18].Title = "Western Australia";
    MapArea[18].Box.h = 48;
    MapArea[18].Box.w = 48;
    MapArea[18].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[18].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[18]);

    MapArea[19].Population = 53997325;
    MapArea[19].Stat = 4;
    MapArea[19].Tax = 0;
    MapArea[19].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[19].Title = "Northern Territories";
    MapArea[19].Box.h = 48;
    MapArea[19].Box.w = 48;
    MapArea[19].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[19].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[19]);

    MapArea[20].Population = 53997325;
    MapArea[20].Stat = 4;
    MapArea[20].Tax = 0;
    MapArea[20].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[20].Title = "New South Wales";
    MapArea[20].Box.h = 48;
    MapArea[20].Box.w = 48;
    MapArea[20].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[20].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[20]);

    MapArea[21].Population = 53997325;
    MapArea[21].Stat = 4;
    MapArea[21].Tax = 0;
    MapArea[21].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[21].Title = "Mauritania";
    MapArea[21].Box.h = 48;
    MapArea[21].Box.w = 48;
    MapArea[21].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[21].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[21]);

    MapArea[22].Population = 53997325;
    MapArea[22].Stat = 4;
    MapArea[22].Tax = 0;
    MapArea[22].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[22].Title = "Nigeria";
    MapArea[22].Box.h = 48;
    MapArea[22].Box.w = 48;
    MapArea[22].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[22].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[22]);

    MapArea[23].Population = 53997325;
    MapArea[23].Stat = 4;
    MapArea[23].Tax = 0;
    MapArea[23].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[23].Title = "Sudan";
    MapArea[23].Box.h = 48;
    MapArea[23].Box.w = 48;
    MapArea[23].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[23].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[23]);

    MapArea[24].Population = 53997325;
    MapArea[24].Stat = 4;
    MapArea[24].Tax = 0;
    MapArea[24].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[24].Title = "Arabia";
    MapArea[24].Box.h = 48;
    MapArea[24].Box.w = 48;
    MapArea[24].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[24].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[24]);

    MapArea[25].Population = 53997325;
    MapArea[25].Stat = 4;
    MapArea[25].Tax = 0;
    MapArea[25].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[25].Title = "Zaire";
    MapArea[25].Box.h = 48;
    MapArea[25].Box.w = 48;
    MapArea[25].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[25].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[25]);

    MapArea[26].Population = 53997325;
    MapArea[26].Stat = 4;
    MapArea[26].Tax = 0;
    MapArea[26].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[26].Title = "Kenya";
    MapArea[26].Box.h = 48;
    MapArea[26].Box.w = 48;
    MapArea[26].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[26].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[26]);

    MapArea[27].Population = 53997325;
    MapArea[27].Stat = 4;
    MapArea[27].Tax = 0;
    MapArea[27].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[27].Title = "South Africa";
    MapArea[27].Box.h = 48;
    MapArea[27].Box.w = 48;
    MapArea[27].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[27].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[27]);

    MapArea[28].Population = 53997325;
    MapArea[28].Stat = 4;
    MapArea[28].Tax = 0;
    MapArea[28].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[28].Title = "Mozambique";
    MapArea[28].Box.h = 48;
    MapArea[28].Box.w = 48;
    MapArea[28].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[28].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[28]);

    MapArea[29].Population = 53997325;
    MapArea[29].Stat = 4;
    MapArea[29].Tax = 0;
    MapArea[29].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[29].Title = "Atlantic Accelerator";
    MapArea[29].Box.h = 48;
    MapArea[29].Box.w = 48;
    MapArea[29].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[29].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[29]);

    MapArea[30].Population = 53997325;
    MapArea[30].Stat = 4;
    MapArea[30].Tax = 0;
    MapArea[30].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[30].Title = "Greenland";
    MapArea[30].Box.h = 48;
    MapArea[30].Box.w = 48;
    MapArea[30].Box.x = 48*30;
    MapArea[30].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[30]);

    MapArea[31].Population = 53997325;
    MapArea[31].Stat = 4;
    MapArea[31].Tax = 0;
    MapArea[31].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[31].Title = "Northeast Territories";
    MapArea[31].Box.h = 48;
    MapArea[31].Box.w = 48;
    MapArea[31].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[31].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[31]);

    MapArea[32].Population = 53997325;
    MapArea[32].Stat = 4;
    MapArea[32].Tax = 0;
    MapArea[32].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[32].Title = "Northwest Territories";
    MapArea[32].Box.h = 48;
    MapArea[32].Box.w = 48;
    MapArea[32].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[32].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[32]);

    MapArea[33].Population = 53997325;
    MapArea[33].Stat = 4;
    MapArea[33].Tax = 0;
    MapArea[33].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[33].Title = "Alaska";
    MapArea[33].Box.h = 48;
    MapArea[33].Box.w = 48;
    MapArea[33].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[33].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[33]);

    MapArea[34].Population = 53997325;
    MapArea[34].Stat = 4;
    MapArea[34].Tax = 0;
    MapArea[34].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[34].Title = "Yukon";
    MapArea[34].Box.h = 48;
    MapArea[34].Box.w = 48;
    MapArea[34].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[34].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[34]);

    MapArea[35].Population = 53997325;
    MapArea[35].Stat = 4;
    MapArea[35].Tax = 0;
    MapArea[35].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[35].Title = "Newfoundland";
    MapArea[35].Box.h = 48;
    MapArea[35].Box.w = 48;
    MapArea[35].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[35].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[35]);

    MapArea[36].Population = 53997325;
    MapArea[36].Stat = 4;
    MapArea[36].Tax = 0;
    MapArea[36].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[36].Title = "California";
    MapArea[36].Box.h = 48;
    MapArea[36].Box.w = 48;
    MapArea[36].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[36].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[36]);

    MapArea[37].Population = 53997325;
    MapArea[37].Stat = 4;
    MapArea[37].Tax = 0;
    MapArea[37].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[37].Title = "Rockies";
    MapArea[37].Box.h = 48;
    MapArea[37].Box.w = 48;
    MapArea[37].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[37].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[37]);

    MapArea[38].Population = 53997325;
    MapArea[38].Stat = 4;
    MapArea[38].Tax = 0;
    MapArea[38].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[38].Title = "Mid West";
    MapArea[38].Box.h = 48;
    MapArea[38].Box.w = 48;
    MapArea[38].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[38].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[38]);

    MapArea[39].Population = 53997325;
    MapArea[39].Stat = 4;
    MapArea[39].Tax = 0;
    MapArea[39].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[39].Title = "New England";
    MapArea[39].Box.h = 48;
    MapArea[39].Box.w = 48;
    MapArea[39].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[39].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[39]);

    MapArea[40].Population = 53997325;
    MapArea[40].Stat = 4;
    MapArea[40].Tax = 0;
    MapArea[40].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[40].Title = "Scandinavia";
    MapArea[40].Box.h = 48;
    MapArea[40].Box.w = 48;
    MapArea[40].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[40].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[40]);

    MapArea[41].Population = 53997325;
    MapArea[41].Stat = 4;
    MapArea[41].Tax = 0;
    MapArea[41].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[41].Title = "Scandinavia";
    MapArea[41].Box.h = 48;
    MapArea[41].Box.w = 48;
    MapArea[41].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[41].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[41]);

    MapArea[42].Population = 53997325;
    MapArea[42].Stat = 4;
    MapArea[42].Tax = 0;
    MapArea[42].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[42].Title = "Scandinavia";
    MapArea[42].Box.h = 48;
    MapArea[42].Box.w = 48;
    MapArea[42].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[42].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[42]);

    MapArea[43].Population = 53997325;
    MapArea[43].Stat = 4;
    MapArea[43].Tax = 0;
    MapArea[43].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[43].Title = "Scandinavia";
    MapArea[43].Box.h = 48;
    MapArea[43].Box.w = 48;
    MapArea[43].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[43].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[43]);

    MapArea[44].Population = 53997325;
    MapArea[44].Stat = 4;
    MapArea[44].Tax = 0;
    MapArea[44].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[44].Title = "Scandinavia";
    MapArea[44].Box.h = 48;
    MapArea[44].Box.w = 48;
    MapArea[44].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[44].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[44]);

    MapArea[45].Population = 53997325;
    MapArea[45].Stat = 4;
    MapArea[45].Tax = 0;
    MapArea[45].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[45].Title = "Scandinavia";
    MapArea[45].Box.h = 48;
    MapArea[45].Box.w = 48;
    MapArea[45].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[45].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[45]);

    MapArea[46].Population = 53997325;
    MapArea[46].Stat = 4;
    MapArea[46].Tax = 0;
    MapArea[46].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[46].Title = "Scandinavia";
    MapArea[46].Box.h = 48;
    MapArea[46].Box.w = 48;
    MapArea[46].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[46].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[46]);

    MapArea[47].Population = 53997325;
    MapArea[47].Stat = 4;
    MapArea[47].Tax = 0;
    MapArea[47].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[47].Title = "Scandinavia";
    MapArea[47].Box.h = 48;
    MapArea[47].Box.w = 48;
    MapArea[47].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[47].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[47]);

    MapArea[48].Population = 53997325;
    MapArea[48].Stat = 4;
    MapArea[48].Tax = 0;
    MapArea[48].TaxPercentage = DEFAULT_TAX_PERCENTAGE;
    MapArea[48].Title = "Scandinavia";
    MapArea[48].Box.h = 48;
    MapArea[48].Box.w = 48;
    MapArea[48].Box.x = rand()%SCREEN_HEIGHT;
    MapArea[48].Box.y = rand()%SCREEN_HEIGHT;
    MapAreaCollision(MapArea[48]);

    BRIEF_BUTTON.h = 32;
    BRIEF_BUTTON.w = 150;
    BRIEF_BUTTON.x = 0;
    BRIEF_BUTTON.y = SCREEN_HEIGHT - 64;

    MENU_BUTTON.h = 32;
    MENU_BUTTON.w = 150;
    MENU_BUTTON.x = SCREEN_WIDTH - 200;
    MENU_BUTTON.y = SCREEN_HEIGHT - 64;

};

void Map()
{
    SDL_Surface* MAP_SURFACE;
    int  x,y;

    MAP_SURFACE = SDL_LoadBMP( "mappy.bmp" );
    //SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
    SDL_Rect box;
    box.h = 48;
    box.w = 48;
    box.x = 0;
    box.y = 0;

    SDL_BlitSurface( MAP_SURFACE, NULL, screenSurface, NULL );

    box.h = 48;
    box.w = 48;
    box.x = 900;
    box.y = 100;

    for(int i=0; i <49; i++)
    {
        SDL_FillRect(screenSurface, &MapArea[i].Box, SDL_MapRGB(screenSurface->format, 0, 0, 255));
        int  x,y;
        SDL_GetMouseState(&x,&y);
        if(x > MapArea[i].Box.x && x < MapArea[i].Box.x + MapArea[i].Box.w && y > MapArea[i].Box.y && y < MapArea[i].Box.y + MapArea[i].Box.h )
        {
            font_printer(MapArea[i].Title.c_str(),12,MapArea[i].Box.x,MapArea[i].Box.y);
            font_printer(intToString(MapArea[i].Population),24,0,SCREEN_HEIGHT - 120);
            font_printer(intToString(MapArea[i].Stat),24,0,SCREEN_HEIGHT - 90);
            font_printer(intToString(MapArea[i].Tax),24,0,SCREEN_HEIGHT - 60);
            font_printer(intToString(MapArea[i].TaxPercentage),24,0,SCREEN_HEIGHT - 30);
            choice = "Mission Briefing";
        }
    }

        SDL_FillRect(screenSurface, &BRIEF_BUTTON, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_GetMouseState(&x,&y);
        if(x > BRIEF_BUTTON.x && x < BRIEF_BUTTON.x + BRIEF_BUTTON.w && y > BRIEF_BUTTON.y && y < BRIEF_BUTTON.y + BRIEF_BUTTON.h )
        {
            SDL_FillRect(screenSurface, &BRIEF_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        }
        SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 0, 255));

        SDL_GetMouseState(&x,&y);
        if(x > MENU_BUTTON.x && x < MENU_BUTTON.x + MENU_BUTTON.w && y > MENU_BUTTON.y && y < MENU_BUTTON.y + MENU_BUTTON.h )
        {
            SDL_FillRect(screenSurface, &MENU_BUTTON, SDL_MapRGB(screenSurface->format, 0, 255, 0));
        }


    //font_printer(ACCEPT_BUTTON_TEXT.c_str(),24,0,SCREEN_HEIGHT -100);
    //font_printer(MENU_BUTTON_TEXT.c_str(),24,SCREEN_WIDTH -300,SCREEN_HEIGHT-100);
    //font_printer(OK_BUTTON_TEXT.c_str(),24,900,400);
    //font_printer(CANCEL_BUTTON_TEXT.c_str(),24,1400,400);
    //font_printer(COLOR_BUTTON_TEXT.c_str(),24,1400,200);
    //font_printer(LOGO_BUTTON_TEXT.c_str(),24,1400,300);

//    SDL_Rect box_top_left;
//    box_top_left.h = 48;
//    box_top_left.w = 48;
//    box_top_left.x = 1250;
//    box_top_left.y = 200;
//    SDL_FillRect(screenSurface, &box_top_left, SDL_MapRGB(screenSurface->format, 0, 0, 255));
//
//    SDL_Rect box_top_right;
//    box_top_right.h = 48;
//    box_top_right.w = 48;
//    box_top_right.x = 1300;
//    box_top_right.y = 200;
//    SDL_FillRect(screenSurface, &box_top_right, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//
//    SDL_Rect box_bottom_left;
//    box_bottom_left.h = 48;
//    box_bottom_left.w = 48;
//    box_bottom_left.x = 1250;
//    box_bottom_left.y = 300;
//    SDL_FillRect(screenSurface, &box_bottom_left, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//
//    SDL_Rect box_bottom_right;
//    box_bottom_right.h = 48;
//    box_bottom_right.w = 48;
//    box_bottom_right.x = 1300;
//    box_bottom_right.y = 300;
//    SDL_FillRect(screenSurface, &box_bottom_right, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//
//    bool submenu = false;
//    if(submenu)
//    {
//        SDL_Rect box_color_and_logo;
//        box_color_and_logo.h = 48;
//        box_color_and_logo.w = 48;
//        box_color_and_logo.x = 1250;
//        box_color_and_logo.y = 200;
//        SDL_FillRect(screenSurface, &box_color_and_logo, SDL_MapRGB(screenSurface->format, 0, 0, 255));
//
//        SDL_Rect box_company_name;
//        box_company_name.h = 48;
//        box_company_name.w = 48;
//        box_company_name.x = 1250;
//        box_company_name.y = 300;
//        SDL_FillRect(screenSurface, &box_company_name, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//
//        SDL_Rect box_your_name;
//        box_your_name.h = 48;
//        box_your_name.w = 48;
//        box_your_name.x = 1250;
//        box_your_name.y = 400;
//        SDL_FillRect(screenSurface, &box_your_name, SDL_MapRGB(screenSurface->format, 0, 255, 0));
//    }
//
//    font_printer(CHANGE_COMPANY_TEXT.c_str(),24,1400,300);
    //accept button
    //menu button
    //color and logo button
    //company name button
    //your name button
    //company logo
    //select details to change text
    //company name string printout
    //your name string printout
    // switch sub window
    // left and right buttons
    // ok button
    // cancel button
    // logo image printed
    // exit back to main menu
    // Alter the taxation of the different areas if owned left and right
    SDL_FreeSurface( MAP_SURFACE );
};

void MainMenu()
{
};

void sleepcp(int milliseconds);

void sleepcp(int milliseconds) // cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;
//The window we'll be rendering to
//SDL_Window* gWindow = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

SDL_Surface* loadSurface( std::string path );

bool loadMedia()
{
    cout << "LOOOOADDDD MEDIA!!!!" << endl;
    sleepcp(3000);

	//Loading success flag
	bool success = true;

	//Load PNG surface
	//gPNGSurface = loadSurface( "eurocorp.png" );
	//if( gPNGSurface == NULL )
	//{
	//	printf( "Failed to load PNG image!\n" );
	//	sleepcp(2000);
	//}

	return success;
}

SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
		sleepcp(2000);
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			sleepcp(2000);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

SDL_Texture* enemyTexture;
SDL_Texture* playerTexture;
SDL_Texture* backgroundTexture;
SDL_Texture* barTexture;

SDL_Texture* IMG_LoadTexture
(
    SDL_Renderer* renderer,
    const char *file
);

SDL_Texture* LoadTexture( const std::string &str )
{
    // Load image as SDL_Surface

    SDL_Texture* texture = IMG_LoadTexture( str.c_str() );
    if ( texture == nullptr )
    {
        std::cout << "Failed to load texture " << str << " error : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}


int main( int argc, char* args[] )
{

	enemyTexture      = LoadTexture( "eurocorp.png" );
	playerTexture     = LoadTexture( "eurocorp.png" );
	backgroundTexture = LoadTexture( "eurocorp.bmp" );
	barTexture        = LoadTexture( "eurocorp.bmp" );

    // General variables
    int i = 0;

    // Loading assets
    std::vector<std::string> words;
    std::ifstream file("./assets/maparea.data");

    std::string word;

    while (file >> word) {
        MapArea[++i].Title = word.c_str();
        cout << MapArea[i].Title << endl;
        sleepcp(50);
        words.push_back(word);
    }
    file.close();

    std::vector<std::string> factions;
    std::ifstream faction_file("./assets/faction.data");

    std::string faction_name;
    i = 0;
    while (faction_file >> faction_name) {
        cout << faction_name << endl;
        sleepcp(50);
        factions.push_back(faction_name);
    }
    faction_file.close();

    vector<string> input;
    ifstream readFile("./assets/maparea.data");
    copy(istream_iterator<std::string>(readFile), {}, back_inserter(input));
    std::cout << "Vector Size is now " << input.size();

    SDL_Init(SDL_INIT_VIDEO);
    cout << "Initialized SDL VIDEO" << endl;
    sleepcp(3000);

    //InitializeMap();
    //InitializeLoadAndSaveGame();
    choice = "main menu";


    for (auto& kv : A::myMap) {
        std::cout << kv.first << " has value " << kv.second.x << "|" << kv.second.y << "|" << kv.second.w << "|" << kv.second.h << std::endl;
    }
    std::cout << A::myMap.at(0).x << std::endl;

    //freopen ("log.txt","w",stdout);

    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL2_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        if(!TTF_WasInit() && TTF_Init()==-1)
        {
            std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
            exit(1);
        }

        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            cout << "IMG_Init failed to initialize" << endl;
            sleepcp(1000);
            exit(EXIT_FAILURE);
        }
        else
        {
            cout << "IMG_Init successfull..." << endl;
            sleepcp(2000);
        }

        //Enable text input
        SDL_StartTextInput();

        window = SDL_CreateWindow(WINDOW_TITLE.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
        if( window == NULL )
        {
            std::cout << "Window not created: " << SDL_GetError() << std::endl;
        }
        else
        {
            cout << "Window created successfull" << endl;
            sleepcp(2000);

            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);

	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( "eurocorp.png" );
	cout << "ERRRRRORRORORRORO" << endl;
	sleepcp(3000);
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "eurocorp.png", IMG_GetError() );
		sleepcp(2000);
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", "eurocorp.png", SDL_GetError() );
			sleepcp(2000);
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}


            while( running )
            {
                fps_sync();
                //Get window surface
                screenSurface = SDL_GetWindowSurface( window );
                //Fill the surface white
                SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0, 0, 0 ) );



            	//Apply the PNG image
				//SDL_FreeSurface(gPNGSurface);

                if(choice == "main menu")
                {
                    //MAIN_MENU_SURFACE = SDL_LoadBMP( MAIN_MENU_SURFACE_IMAGE.c_str() );
                    //SDL_BlitSurface( MAIN_MENU_SURFACE, NULL, screenSurface, NULL );
                    //SDL_FreeSurface(MAIN_MENU_SURFACE);

                    SDL_BlitSurface( gPNGSurface, NULL, screenSurface, NULL );
                    //SDL_UpdateWindowSurface( window );
                }

                 while( SDL_PollEvent( &event ) != 0 )
                {
                    if( event.type == SDL_QUIT )
                    {
                        if(choice == "main menu")
                        running = false;
                        else
                        choice = "main menu";
                    }
                    if (event.type == SDL_KEYDOWN)
                    {
                        if ( event.key.keysym.sym == SDLK_ESCAPE )
                        {
                            if(choice == "main menu")
                            running = false;
                            else
                            choice = "main menu";
                        }
                    }
                    if( event.type == SDL_MOUSEBUTTONUP )
                    {
                        if( event.button.state == SDL_RELEASED && event.button.button == SDL_BUTTON_LEFT)
                        {
                            //Get the mouse offsets
                            int x = event.button.x;
                            int y = event.button.y;

                            std::cout << "X:_" << x << "Y:_" << y << std::endl;


                            if( choice == "main menu")
                            {
                                if( ( x > A::myMap.at(0).x ) && ( x < A::myMap.at(0).x + A::myMap.at(0).w ) && ( y > A::myMap.at(0).y ) && ( y < A::myMap.at(0).y + A::myMap.at(0).h ) )
                                {
                                    CONFIGURE_COMPANY_BUTTON_PRESSED = false;
                                    std::cout << "Pressing a button like hell" << std::endl;
                                    SDL_FillRect(screenSurface, &A::myMap.at(0), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                                    choice = "configure company";
                                }
                                if( ( x > A::myMap.at(1).x ) && ( x < A::myMap.at(1).x + A::myMap.at(1).w ) && ( y > A::myMap.at(1).y ) && ( y < A::myMap.at(1).y + A::myMap.at(1).h ) )
                                {
                                    BEGIN_MISSION_BUTTON_PRESSED = false;
                                    std::cout << "Pressing a button like hell" << std::endl;
                                    SDL_FillRect(screenSurface, &A::myMap.at(1), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                                    choice = "begin mission";
                                }
                                if( ( x > A::myMap.at(2).x ) && ( x < A::myMap.at(2).x + A::myMap.at(2).w ) && ( y > A::myMap.at(2).y ) && ( y < A::myMap.at(2).y + A::myMap.at(2).h ) )
                                {
                                    LOAD_AND_SAVE_GAME_BUTTON_PRESSED = false;
                                    std::cout << "Pressing a button like hell" << std::endl;
                                    SDL_FillRect(screenSurface, &A::myMap.at(2), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                                    choice = "load and save game";
                                }
                                if( ( x > A::myMap.at(3).x ) && ( x < A::myMap.at(3).x + A::myMap.at(3).w ) && ( y > A::myMap.at(3).y ) && ( y < A::myMap.at(3).y + A::myMap.at(3).h ) )
                                {
                                    RESTART_GAME_BUTTON_PRESSED = false;
                                    std::cout << "Pressing a button like hell" << std::endl;
                                    SDL_FillRect(screenSurface, &A::myMap.at(3), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                                    choice = "restart game";
                                }
                            }

                            if( choice == "load and save game")
                            {
                                for( int i = 0; i < 10; i++)
                                if( ( x > SAVE_GAME_BUTTON[i].x ) && ( x < SAVE_GAME_BUTTON[i].x + SAVE_GAME_BUTTON[i].w ) && ( y > SAVE_GAME_BUTTON[i].y ) && ( y < SAVE_GAME_BUTTON[i].y + SAVE_GAME_BUTTON[i].h ) )
                                {
                                    SDL_FillRect(screenSurface, &SAVE_GAME_BUTTON[i], SDL_MapRGB(screenSurface->format, 255, 0, 0));
                                    std::cout << "Pressed savegame " << i << std::endl;
                                }
                            }
                            if( choice == "configure company")
                            {
                                if( ( x > A::myMap.at(4).x ) && ( x < A::myMap.at(4).x + A::myMap.at(4).w ) && ( y > A::myMap.at(4).y ) && ( y < A::myMap.at(4).y + A::myMap.at(4).h ) )
                                {
                                    LOGO_ID_ACTIVE--;
                                }
                                if( ( x > A::myMap.at(5).x ) && ( x < A::myMap.at(5).x + A::myMap.at(5).w ) && ( y > A::myMap.at(5).y ) && ( y < A::myMap.at(5).y + A::myMap.at(5).h ) )
                                {
                                    LOGO_ID_ACTIVE--;
                                }
                                if( ( x > A::myMap.at(6).x ) && ( x < A::myMap.at(6).x + A::myMap.at(6).w ) && ( y > A::myMap.at(6).y ) && ( y < A::myMap.at(6).y + A::myMap.at(6).h ) )
                                {
                                    LOGO_ID_ACTIVE++;
                                }
                                if( ( x > A::myMap.at(7).x ) && ( x < A::myMap.at(7).x + A::myMap.at(7).w ) && ( y > A::myMap.at(7).y ) && ( y < A::myMap.at(7).y + A::myMap.at(7).h ) )
                                {
                                    LOGO_ID_ACTIVE++;
                                }
                            }
                        }
                    }
                    if( event.type == SDL_MOUSEBUTTONDOWN )
                    {
                        if( event.button.state == SDL_PRESSED)
                        {
                            if ( event.button.button == SDL_BUTTON_LEFT)
                            {
                                //Get the mouse offsets
                                int x = event.button.x;
                                int y = event.button.y;

                                std::cout << "X:_" << x << "Y:_" << y << std::endl;

//                                //If the mouse is over the button
//                                if( ( x > A::myMap.at(0).x ) && ( x < A::myMap.at(0).x + A::myMap.at(0).w ) && ( y > A::myMap.at(0).y ) && ( y < A::myMap.at(0).y + A::myMap.at(0).h ) )
//                                {
//                                    CONFIGURE_COMPANY_BUTTON_PRESSED = true;
//                                    std::cout << "Pressing a button like hell" << std::endl;
//                                    SDL_FillRect(screenSurface, &A::myMap.at(0), SDL_MapRGB(screenSurface->format, 0, 255, 0));
//                                }
//                                if( ( x > A::myMap.at(1).x ) && ( x < A::myMap.at(1).x + A::myMap.at(1).w ) && ( y > A::myMap.at(1).y ) && ( y < A::myMap.at(1).y + A::myMap.at(1).h ) )
//                                {
//                                    BEGIN_MISSION_BUTTON_PRESSED = true;
//                                    std::cout << "Pressing a button like hell" << std::endl;
//                                    SDL_FillRect(screenSurface, &A::myMap.at(1), SDL_MapRGB(screenSurface->format, 0, 255, 0));
//                                }
//                                if( ( x > A::myMap.at(2).x ) && ( x < A::myMap.at(2).x + A::myMap.at(2).w ) && ( y > A::myMap.at(2).y ) && ( y < A::myMap.at(2).y + A::myMap.at(2).h ) )
//                                {
//                                    LOAD_AND_SAVE_GAME_BUTTON_PRESSED = true;
//                                    std::cout << "Pressing a button like hell" << std::endl;
//                                    SDL_FillRect(screenSurface, &A::myMap.at(2), SDL_MapRGB(screenSurface->format, 0, 255, 0));
//                                }
//                                if( ( x > A::myMap.at(3).x ) && ( x < A::myMap.at(3).x + A::myMap.at(3).w ) && ( y > A::myMap.at(3).y ) && ( y < A::myMap.at(3).y + A::myMap.at(3).h ) )
//                                {
//                                    RESTART_GAME_BUTTON_PRESSED = true;
//                                    std::cout << "Pressing a button like hell" << std::endl;
//                                    SDL_FillRect(screenSurface, &A::myMap.at(3), SDL_MapRGB(screenSurface->format, 0, 255, 0));
//                                }
                            }
                        }
                    }
                }

                //If the mouse is over the button
                if( CONFIGURE_COMPANY_BUTTON_PRESSED )
                {
                    std::cout << "Pressing a button like hell" << std::endl;
                    SDL_FillRect(screenSurface, &A::myMap.at(0), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                }
                if( BEGIN_MISSION_BUTTON_PRESSED )
                {
                    std::cout << "Pressing a button like hell" << std::endl;
                    SDL_FillRect(screenSurface, &A::myMap.at(1), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                }
                if( LOAD_AND_SAVE_GAME_BUTTON_PRESSED )
                {
                    std::cout << "Pressing a button like hell" << std::endl;
                    SDL_FillRect(screenSurface, &A::myMap.at(2), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                }
                if( RESTART_GAME_BUTTON_PRESSED )
                {
                    std::cout << "Pressing a button like hell" << std::endl;
                    SDL_FillRect(screenSurface, &A::myMap.at(3), SDL_MapRGB(screenSurface->format, 0, 255, 0));
                }

                font_printer(choice.c_str(),48,SCREEN_WIDTH - 1180,0);

                if(choice == "main menu" )
                {
                    //SDL_BlitSurface( MAIN_MENU_SURFACE, NULL, screenSurface, NULL );
                    font_printer(MAIN_MENU_TITLE.c_str(),100,320,100);
                    font_printer(CONFIGURE_COMPANY_BUTTON_TEXT.c_str(),48,700,300);
                    font_printer(BEGIN_MISSION_BUTTON_TEXT.c_str(),48,700,500);
                    font_printer(LOAD_AND_SAVE_GAME_BUTTON_TEXT.c_str(),48,700,700);
                    font_printer(RESTART_GAME_BUTTON_TEXT.c_str(),48,700,900);
                }

                if(choice == "configure company")
                ConfigureCompany();
                if(choice == "begin mission")
                Map();
                if(choice == "Mission Briefing")
                MissionBriefing();
                if(choice == "load and save game")
                LoadAndSaveGame();

                //Update the surface
                SDL_UpdateWindowSurface( window );
                //Wait two seconds
                //SDL_Delay( 2000 );

                int MouseXCoordinates, MouseYCoordinates;
                SDL_GetMouseState(&MouseXCoordinates, &MouseYCoordinates);
                std::cout << "(" << MouseXCoordinates << "," << MouseYCoordinates << ")" << std::endl;
            }
        }


        //gWindow = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        //gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);
        //SDL_SetRenderDrawBlendMode(gRenderer,SDL_BLENDMODE_NONE);

        //SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
        //FullScreenGlobal(window,SDL_WINDOW_FULLSCREEN_DESKTOP);

        screen = SDL_GetWindowSurface( window );
        MAIN_MENU_SURFACE = SDL_LoadBMP( MAIN_MENU_SURFACE_IMAGE.c_str() );
        image = SDL_LoadBMP( "syndicate/main_menu.bmp" );




        std::string inputText = "Some Text";
        bool renderText = false;
        //Enable text input
        SDL_StartTextInput();

        SDL_Rect dstrecta;

        while( running )
        {
            int MouseXCoordinates, MouseYCoordinates;
            SDL_GetMouseState(&MouseXCoordinates, &MouseYCoordinates);
            std::cout << "(" << MouseXCoordinates << "," << MouseYCoordinates << ")" << std::endl;

            // current date/time based on current system
            time_t now = time(0);

            // convert now to string form
            char* dt = ctime(&now);

            std::cout << "The local date and time is: " << dt << std::endl;

            // convert now to tm struct for UTC
            tm *gmtm = gmtime(&now);
            dt = asctime(gmtm);
            std::cout << "The UTC date and time is:"<< dt << std::endl;

            fps_sync();
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));


            while( SDL_PollEvent( &event ) != 0 )
            {
                if( event.type == SDL_QUIT )
                {
                    running = false;
                }
                if( event.type == SDL_MOUSEBUTTONUP )
                {
                    if( event.button.state == SDL_RELEASED && event.button.button == SDL_BUTTON_LEFT)
                    {
                        //Get the mouse offsets
                        int x = event.button.x;
                        int y = event.button.y;

                        std::cout << "X:_" << x << "Y:_" << y << std::endl;

                        //dstrecta.x = MouseXCoordinates;
                        //dstrecta.y = MouseYCoordinates;
                        //dstrecta.w = 0;
                        //dstrecta.h = 0;

                        //If the mouse is over the button
                        if( ( x > A::myMap.at(0).x ) && ( x < A::myMap.at(0).x + A::myMap.at(0).w ) && ( y > A::myMap.at(0).y ) && ( y < A::myMap.at(0).y + A::myMap.at(0).h ) )
                        {
                            CONFIGURE_COMPANY_BUTTON_PRESSED = false;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
                            choice = "configure company";
                        }
                        if( ( x > A::myMap.at(1).x ) && ( x < A::myMap.at(1).x + A::myMap.at(1).w ) && ( y > A::myMap.at(1).y ) && ( y < A::myMap.at(1).y + A::myMap.at(1).h ) )
                        {
                            BEGIN_MISSION_BUTTON_PRESSED = false;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(1), SDL_MapRGB(screen->format, 0, 255, 0));
                            choice = "begin mission";
                        }
                        if( ( x > A::myMap.at(2).x ) && ( x < A::myMap.at(2).x + A::myMap.at(2).w ) && ( y > A::myMap.at(2).y ) && ( y < A::myMap.at(2).y + A::myMap.at(2).h ) )
                        {
                            LOAD_AND_SAVE_GAME_BUTTON_PRESSED = false;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(2), SDL_MapRGB(screen->format, 0, 255, 0));
                            choice = "load and save game";
                        }
                        if( ( x > A::myMap.at(3).x ) && ( x < A::myMap.at(3).x + A::myMap.at(3).w ) && ( y > A::myMap.at(3).y ) && ( y < A::myMap.at(3).y + A::myMap.at(3).h ) )
                        {
                            RESTART_GAME_BUTTON_PRESSED = false;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(3), SDL_MapRGB(screen->format, 0, 255, 0));
                            choice = "restart game";
                        }
                    }
                }
                if( event.type == SDL_MOUSEBUTTONDOWN )
                {
                    if( event.button.state == SDL_PRESSED)
                    if ( event.button.button == SDL_BUTTON_LEFT)
                    {
                        //Get the mouse offsets
                        int x = event.button.x;
                        int y = event.button.y;

                        std::cout << "X:_" << x << "Y:_" << y << std::endl;

                        //dstrecta.x = MouseXCoordinates;
                        //dstrecta.y = MouseYCoordinates;
                        //dstrecta.w = 965;
                        //dstrecta.h = 162;

                        //If the mouse is over the button
                        if( ( x > A::myMap.at(0).x ) && ( x < A::myMap.at(0).x + A::myMap.at(0).w ) && ( y > A::myMap.at(0).y ) && ( y < A::myMap.at(0).y + A::myMap.at(0).h ) )
                        {
                            CONFIGURE_COMPANY_BUTTON_PRESSED = true;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                        if( ( x > A::myMap.at(1).x ) && ( x < A::myMap.at(1).x + A::myMap.at(1).w ) && ( y > A::myMap.at(1).y ) && ( y < A::myMap.at(1).y + A::myMap.at(1).h ) )
                        {
                            BEGIN_MISSION_BUTTON_PRESSED = true;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(1), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                        if( ( x > A::myMap.at(2).x ) && ( x < A::myMap.at(2).x + A::myMap.at(2).w ) && ( y > A::myMap.at(2).y ) && ( y < A::myMap.at(2).y + A::myMap.at(2).h ) )
                        {
                            LOAD_AND_SAVE_GAME_BUTTON_PRESSED = true;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(2), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                        if( ( x > A::myMap.at(3).x ) && ( x < A::myMap.at(3).x + A::myMap.at(3).w ) && ( y > A::myMap.at(3).y ) && ( y < A::myMap.at(3).y + A::myMap.at(3).h ) )
                        {
                            RESTART_GAME_BUTTON_PRESSED = true;
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(3), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                    }

                }
                if (event.type == SDL_KEYDOWN)
                {
                    std::cout << inputText << std::endl;
                    //printf("player X %d\n", Player.x);

                    if ( event.key.keysym.sym == SDLK_ESCAPE )
                    {
                        running = false;
                    }
                    if ( event.key.keysym.sym == SDLK_LEFT )
                    {
                                  //if((int)Player.x - (int)Camera.x + (SCREEN_WIDTH/2) != 0)
                                //if(!tileCollision(x-1, y, TILESIZE, TILESIZE))
                            std::cout << "Get a move on soldier" << std::endl;
                            Player.x += 1;
                    }

                    //Handle backspace
                    if( event.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
                    {
                        std::cout << "Deleting something" << std::endl;
                        //pop off character
                        inputText.pop_back(); renderText = true;
                    } //Handle copy
                    else
                    if( event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
                    {
                        SDL_SetClipboardText( inputText.c_str() );
                    } //Handle paste
                    else if( event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
                    {
                        inputText = SDL_GetClipboardText(); renderText = true;
                    }
                    //char c = event.key.keysym.unicode;
                }
                                     //Special text input event
                 else if( event.type == SDL_TEXTINPUT )
                 {
                    std::cout << "Handle input" << std::endl;
                  //Not copy or pasting
                 if( !( ( event.text.text[ 0 ] == 'c' || event.text.text[ 0 ] == 'C' ) && ( event.text.text[ 0 ] == 'v' || event.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
                 {
                    std::cout << "appending text" << std::endl;
                    //Append character
                    inputText += event.text.text; renderText = true;
                 }
                 }



            }

            // Render some text in solid black to a new surface
            // then blit to the upper left of the screen
            // then free the text surface
            //SDL_Surface *screen;

            //drawbackground();
            //Draw();

            SDL_Color color={0,255,0};
            SDL_Surface *text_surface;

SDL_Rect srcrect;
SDL_Rect dstrect;

srcrect.x = 0;
srcrect.y = 0;
srcrect.w = 32;
srcrect.h = 32;
dstrect.x = 0;
dstrect.y = 0;
dstrect.w = 32;
dstrect.h = 32;

            //font_printer("Party Information",48,dstrect);

srcrect.x = 0;
srcrect.y = 0;
srcrect.w = 32;
srcrect.h = 32;
dstrect.x = 640/2;
dstrect.y = 480/4;
dstrect.w = 32;
dstrect.h = 32;

            //font_printer("Name\t\tHits\t\tSpells\t\tStatus\t\tOption",24,dstrect);
srcrect.x = 0;
srcrect.y = 0;
srcrect.w = 32;
srcrect.h = 32;
dstrect.x = 640/2;
dstrect.y = 480/3;
dstrect.w = 32;
dstrect.h = 32;
            //font_printer("Caretaker\t12/12\t\t120\t\tOk\t\tNone",24,dstrect);
 srcrect.x = 0;
srcrect.y = 0;
srcrect.w = 32;
srcrect.h = 32;
dstrect.x = 640/2;
dstrect.y = 480/2;
dstrect.w = 32;
dstrect.h = 32;
            //font_printer(inputText.c_str(),24,dstrect);

dstrect.x = 500;
dstrect.y = 0;
dstrect.w = 32;
dstrect.h = 32;

std::stringstream ss;
//ss << t;

ss << dt;

std::string str = ss.str();

            font_printer(str.c_str(),48,500,0);


                //SDL_FillRect(screen, &dstrecta, SDL_MapRGB(screen->format, 0, 255, 0));
//                SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
//                SDL_FillRect(screen, &A::myMap.at(1), SDL_MapRGB(screen->format, 0, 255, 0));
//                SDL_FillRect(screen, &A::myMap.at(2), SDL_MapRGB(screen->format, 0, 255, 0));
//                SDL_FillRect(screen, &A::myMap.at(3), SDL_MapRGB(screen->format, 0, 255, 0));

//            if(!(text_surface=TTF_RenderText_Solid(font,"Party Information",color)))
//            {
//                std::cout << "Hey we got a error ehere" << std::endl;
//                //handle error here, perhaps print TTF_GetError at least
//            }
//            else
//            {
//                SDL_BlitSurface(text_surface,NULL,screen,NULL);
//                //perhaps we can reuse it, but I assume not for simplicity.
//                SDL_FreeSurface(text_surface);
//            }

                        //If the mouse is over the button
                        if( CONFIGURE_COMPANY_BUTTON_PRESSED )
                        {
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(0), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                        if( BEGIN_MISSION_BUTTON_PRESSED )
                        {
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(1), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                        if( LOAD_AND_SAVE_GAME_BUTTON_PRESSED )
                        {
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(2), SDL_MapRGB(screen->format, 0, 255, 0));
                        }
                        if( RESTART_GAME_BUTTON_PRESSED )
                        {
                            std::cout << "Pressing a button like hell" << std::endl;
                            SDL_FillRect(screen, &A::myMap.at(3), SDL_MapRGB(screen->format, 0, 255, 0));
                        }

            SDL_FillRect(screen, &A::myMap.at(2), SDL_MapRGB(screen->format, 0, 255, 0));
            font_printer(choice.c_str(),48,SCREEN_WIDTH - 1180,0);

            if(choice != "configure company" || choice != "begin mission" || choice != "Mission Briefing")
            {
                //SDL_BlitSurface( MAIN_MENU_SURFACE, NULL, screen, NULL );
                font_printer(MAIN_MENU_TITLE.c_str(),100,320,100);
                font_printer(CONFIGURE_COMPANY_BUTTON_TEXT.c_str(),48,700,300);
                font_printer(BEGIN_MISSION_BUTTON_TEXT.c_str(),48,700,500);
                font_printer(LOAD_AND_SAVE_GAME_BUTTON_TEXT.c_str(),48,700,700);
                font_printer(RESTART_GAME_BUTTON_TEXT.c_str(),48,700,900);
            }
            if(choice == "configure company")
            ConfigureCompany();
            if(choice == "begin mission")
            Map();
            if(choice == "Mission Briefing")
            MissionBriefing();

            SDL_UpdateWindowSurface( window );

            //Render red filled quad
            //SDL_RenderClear(gRenderer);

            //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
            //SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            //SDL_RenderFillRect( gRenderer, &fillRect );
            //SDL_RenderFillRect(gRenderer,0);
            //SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
            //SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
            //SDL_RenderPresent( gRenderer );

            //ClearScreen();
            //print_party_information();
        }
  }
  //SDL_DestroyRenderer(gRenderer);
  //SDL_DestroyWindow(gWindow);
  SDL_FreeSurface( image );
  SDL_DestroyWindow( window );
  SDL_Quit();
    fclose (stdout);
  return 0;
}
