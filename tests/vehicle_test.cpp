#include <memory>
#include <vector>

#include "catch/catch.hpp"
#include "game.h"
#include "map.h"
#include "map_helpers.h"
#include "player.h"
#include "vehicle.h"
#include "enums.h"
#include "type_id.h"

TEST_CASE( "detaching_vehicle_unboards_passengers" )
{
    clear_map();
    const tripoint test_origin( 60, 60, 0 );
    const tripoint vehicle_origin = test_origin;
    vehicle *veh_ptr = g->m.add_vehicle( vproto_id( "bicycle" ), vehicle_origin, -90, 0, 0 );
    g->m.board_vehicle( test_origin, &g->u );
    REQUIRE( g->u.in_vehicle );
    g->m.detach_vehicle( veh_ptr );
    REQUIRE( !g->u.in_vehicle );
}

TEST_CASE( "destroy_grabbed_vehicle_section" )
{
    GIVEN( "A vehicle grabbed by the player" ) {
        const tripoint test_origin( 60, 60, 0 );
        g->place_player( test_origin );
        const tripoint vehicle_origin = test_origin + tripoint( 1, 1, 0 );
        vehicle *veh_ptr = g->m.add_vehicle( vproto_id( "bicycle" ), vehicle_origin, -90, 0, 0 );
        REQUIRE( veh_ptr != nullptr );
        tripoint grab_point = test_origin + tripoint( 1, 0, 0 );
        g->u.grab( OBJECT_VEHICLE, grab_point );
        REQUIRE( g->u.get_grab_type() != OBJECT_NONE );
        REQUIRE( g->u.grab_point == grab_point );
        WHEN( "The vehicle section grabbed by the player is destroyed" ) {
            g->m.destroy( grab_point );
            REQUIRE( veh_ptr->get_parts_at( grab_point, "", part_status_flag::available ).empty() );
            THEN( "The player's grab is released" ) {
                CHECK( g->u.get_grab_type() == OBJECT_NONE );
                CHECK( g->u.grab_point == tripoint_zero );
            }
        }
    }
}
