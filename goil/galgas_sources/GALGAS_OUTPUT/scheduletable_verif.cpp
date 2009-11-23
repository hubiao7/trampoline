//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'scheduletable_verif.cpp'                       *
//                        Generated by version 1.9.5                         *
//                     november 23th, 2009, at 12h5'35"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 614
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "scheduletable_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "scheduletable_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "schedule_tables_well_formed"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_schedule_tables_well_formed (C_Compiler & inLexique,
                                const GGS_scheduletable_map   var_cas_sts,
                                const GGS_root_obj   var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_schedule_tables_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_scheduletable_map::cEnumerator enumerator_502 (var_cas_sts, true) ;
    const GGS_scheduletable_map::cElement * operand_502 = NULL ;
    while (((operand_502 = enumerator_502.nextObject ()))) {
      macroValidPointer (operand_502) ;
      GGS_bool var_cas_perio = function_get_bool (inLexique, operand_502->mInfo.st.reader_periodic (inLexique COMMA_SOURCE_FILE_AT_LINE (18)), GGS_bool (false) COMMA_SOURCE_FILE_AT_LINE (18)) ;
      GGS_uint64  var_cas_len = function_uint64_or_error (inLexique, operand_502->mInfo.st.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (20)), GGS_string ("LENGTH") COMMA_SOURCE_FILE_AT_LINE (20)) ;
      { const GGS_ltgt_sync_obj _var_1304 = operand_502->mInfo.st.reader_ltgt_sync (inLexique COMMA_SOURCE_FILE_AT_LINE (23)) ; // CAST instruction
        if (_var_1304.getPtr () != NULL) {
          macroValidPointer (_var_1304.getPtr ()) ;
          if (typeid (cPtr_ltgt_sync_true) == typeid (* (_var_1304.getPtr ()))) {
            const GGS_ltgt_sync_true var_cas_sync (_var_1304.getPtr ()) ;
            const GGS_bool cond_1027 = (var_cas_perio).operator_isEqual (GGS_bool (false)) ;
            if (cond_1027.isBuiltAndTrue ()) {
              operand_502->mInfo.st.reader_periodic (inLexique COMMA_SOURCE_FILE_AT_LINE (26)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (26)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("A synchronized schedule table shall be repeating otherwise, synchronisation can't be done.") COMMA_SOURCE_FILE_AT_LINE (27)) ;
            }
            GGS_uint64  var_cas_prec = function_uint64_or_error (inLexique, var_cas_sync.reader_precision (inLexique COMMA_SOURCE_FILE_AT_LINE (28)), GGS_string ("PRECISION") COMMA_SOURCE_FILE_AT_LINE (28)) ;
            const GGS_bool cond_1287 = (var_cas_prec).operator_strictSup (var_cas_len.add_operation (inLexique, GGS_uint64 (1ULL) COMMA_SOURCE_FILE_AT_LINE (29))) ;
            if (cond_1287.isBuiltAndTrue ()) {
              var_cas_sync.reader_precision (inLexique COMMA_SOURCE_FILE_AT_LINE (30)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (30)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("OS438 - An explicit schedule table shall have a precision in the range 0 to duration.") COMMA_SOURCE_FILE_AT_LINE (31)) ;
            }
          }else{
          }
        }
      }
      const GGS_bool cond_1481 = (var_cas_len).operator_isEqual (GGS_uint64 (0ULL)) ;
      if (cond_1481.isBuiltAndTrue ()) {
        operand_502->mInfo.st.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (36)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (36)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("The LENGTH attribute should not be 0") COMMA_SOURCE_FILE_AT_LINE (37)) ;
      }
      GGS_expiry_point_list  var_cas_eps = operand_502->mInfo.st.reader_exp_points (inLexique COMMA_SOURCE_FILE_AT_LINE (39)) ;
      GGS_uint  var_cas_exp_pt_number = var_cas_eps.reader_length () ;
      const GGS_bool cond_1778 = (var_cas_exp_pt_number).operator_isEqual (GGS_uint (0U)) ;
      if (cond_1778.isBuiltAndTrue ()) {
        operand_502->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("OS401 - no EXPIRY_POINT found for SCHEDULETABLE ")).operator_concat (operand_502->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (44))) COMMA_SOURCE_FILE_AT_LINE (45)) ;
      }
      {
        GGS_expiry_point_list::cEnumerator enumerator_1855 (var_cas_eps, true) ;
        const GGS_expiry_point_list::cElement * operand_1855 = NULL ;
        while (((operand_1855 = enumerator_1855.nextObject ()))) {
          macroValidPointer (operand_1855) ;
          const GGS_bool cond_2007 = (operand_1855->point.reader_actions (inLexique COMMA_SOURCE_FILE_AT_LINE (49)).reader_length ()).operator_isEqual (GGS_uint (0U)) ;
          if (cond_2007.isBuiltAndTrue ()) {
            operand_1855->point.reader_name (inLexique COMMA_SOURCE_FILE_AT_LINE (50)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("OS407 - no ACTION found for EXPIRY_POINT ")).operator_concat (operand_1855->point.reader_name (inLexique COMMA_SOURCE_FILE_AT_LINE (50)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (50))) COMMA_SOURCE_FILE_AT_LINE (51)) ;
          }
        }
      }
      GGS_uint64  var_cas_previous_offset = GGS_uint64 (0ULL) ;
      GGS_uint64  var_cas_first_delay = GGS_uint64 (0ULL) ;
      GGS_uint64  var_cas_first_maxret = GGS_uint64 (0ULL) ;
      GGS_uint64  var_cas_first_maxadv = GGS_uint64 (0ULL) ;
      GGS_uint64  var_cas_last_delay = GGS_uint64 (0ULL) ;
      GGS_bool var_cas_first_time = GGS_bool (true) ;
      GGS_uint64  var_cas_previous_delay = GGS_uint64 (0ULL) ;
      GGS_uint64  var_cas_maxret = GGS_uint64 (0ULL) ;
      GGS_uint64  var_cas_maxadv = GGS_uint64 (0ULL) ;
      GGS_uint  var_cas_i = GGS_uint (0U) ;
      GGS_counter_map  var_cas_counters = var_cas_cpu.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (71)) ;
      const GGS_bool cond_10252 = var_cas_counters.reader_hasKey (operand_502->mInfo.st.reader_counter (inLexique COMMA_SOURCE_FILE_AT_LINE (72)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (72))) ;
      if (cond_10252.isBuiltAndTrue ()) {
        GGS_counter_obj  var_cas_cnt ;
        const GGS_counter_map  temp_2745 = var_cas_counters ;
        if (temp_2745.isBuilt ()) {
          temp_2745 (HERE)->method_getCounter (inLexique, operand_502->mInfo.st.reader_counter (inLexique COMMA_SOURCE_FILE_AT_LINE (74)), var_cas_cnt COMMA_SOURCE_FILE_AT_LINE (74)) ;
        }
        GGS_uint64  var_cas_mav = function_uint32_or_error (inLexique, var_cas_cnt.reader_max_allowed_value (inLexique COMMA_SOURCE_FILE_AT_LINE (75)), GGS_string ("MAXALLOWEDVALUE") COMMA_SOURCE_FILE_AT_LINE (75)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (75)) ;
        GGS_uint64  var_cas_mc = function_uint32_or_error (inLexique, var_cas_cnt.reader_min_cycle (inLexique COMMA_SOURCE_FILE_AT_LINE (76)), GGS_string ("MINCYCLE") COMMA_SOURCE_FILE_AT_LINE (76)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (76)) ;
        GGS_bool var_cas_first_ep = GGS_bool (true) ;
        GGS_uint64  var_cas_previous_offset = GGS_uint64 (0ULL) ;
        {
          GGS_expiry_point_list::cEnumerator enumerator_3023 (var_cas_eps, true) ;
          const GGS_expiry_point_list::cElement * operand_3023 = NULL ;
          while (((operand_3023 = enumerator_3023.nextObject ()))) {
            macroValidPointer (operand_3023) ;
            var_cas_i = var_cas_i.add_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (82)) ;
            GGS_uint64  var_cas_offset = function_uint64_or_error (inLexique, operand_3023->point.reader_offset (inLexique COMMA_SOURCE_FILE_AT_LINE (86)), GGS_string ("OS442 - OFFSET") COMMA_SOURCE_FILE_AT_LINE (86)) ;
            GGS_location  var_cas_off_loc = operand_3023->point.reader_offset (inLexique COMMA_SOURCE_FILE_AT_LINE (87)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (87)) ;
            const GGS_bool cond_3480 = (var_cas_offset).operator_strictSup (var_cas_len) ;
            if (cond_3480.isBuiltAndTrue ()) {
              var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("OFFSET of expiry point is greater than the LENGTH of the Schedule Table ")).operator_concat (operand_502->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (89))) COMMA_SOURCE_FILE_AT_LINE (90)) ;
            }
            var_cas_previous_delay = var_cas_offset.substract_operation (inLexique, var_cas_previous_offset COMMA_SOURCE_FILE_AT_LINE (95)) ;
            const GGS_bool cond_3848 = (var_cas_previous_offset).operator_isEqual (GGS_uint64 (0ULL)) ;
            if (cond_3848.isBuiltAndTrue ()) {
              var_cas_first_delay = var_cas_offset ;
            }
            GGS_location  var_cas_adj_loc = operand_3023->point.reader_adjust (inLexique COMMA_SOURCE_FILE_AT_LINE (100)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (100)) ;
            { const GGS_adjustable_obj _var_5098 = operand_3023->point.reader_adjust (inLexique COMMA_SOURCE_FILE_AT_LINE (101)) ; // CAST instruction
              if (_var_5098.getPtr () != NULL) {
                macroValidPointer (_var_5098.getPtr ()) ;
                if (typeid (cPtr_adjustable_true) == typeid (* (_var_5098.getPtr ()))) {
                  const GGS_adjustable_true var_cas_adj (_var_5098.getPtr ()) ;
                  var_cas_maxret = function_uint64_or_error (inLexique, var_cas_adj.reader_max_retard (inLexique COMMA_SOURCE_FILE_AT_LINE (103)), GGS_string ("MAX_RETARD") COMMA_SOURCE_FILE_AT_LINE (103)) ;
                  var_cas_maxadv = function_uint64_or_error (inLexique, var_cas_adj.reader_max_advance (inLexique COMMA_SOURCE_FILE_AT_LINE (104)), GGS_string ("MAX_ADVANCE") COMMA_SOURCE_FILE_AT_LINE (104)) ;
                  const GGS_bool cond_4408 = (var_cas_previous_offset).operator_isEqual (GGS_uint64 (0ULL)) ;
                  if (cond_4408.isBuiltAndTrue ()) {
                    var_cas_first_maxret = var_cas_maxret ;
                    var_cas_first_maxadv = var_cas_maxadv ;
                  }else if (cond_4408.isBuiltAndFalse ()) {
                    const GGS_bool cond_4729 = (var_cas_maxret).operator_strictSup (var_cas_previous_delay.substract_operation (inLexique, var_cas_mc COMMA_SOURCE_FILE_AT_LINE (111))) ;
                    if (cond_4729.isBuiltAndTrue ()) {
                      var_cas_adj_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((((((GGS_string ("OS436 - In expiry point at offset = ")).operator_concat (var_cas_offset.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (112)))).operator_concat (GGS_string (", MaxRetard ("))).operator_concat (var_cas_maxret.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (112)))).operator_concat (GGS_string (") should be inferior to the previous delay ("))).operator_concat (var_cas_previous_delay.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (112)))).operator_concat (GGS_string (") minus MINCYCLE of the counter ("))).operator_concat (var_cas_mc.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (112)))).operator_concat (GGS_string (").")) COMMA_SOURCE_FILE_AT_LINE (113)) ;
                    }
                    const GGS_bool cond_5044 = (var_cas_maxadv).operator_strictSup (var_cas_len.substract_operation (inLexique, var_cas_previous_delay COMMA_SOURCE_FILE_AT_LINE (114))) ;
                    if (cond_5044.isBuiltAndTrue ()) {
                      var_cas_adj_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((((((GGS_string ("OS437 - In expiry point at offset = ")).operator_concat (var_cas_offset.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (115)))).operator_concat (GGS_string (", MaxAdvance ("))).operator_concat (var_cas_maxadv.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (115)))).operator_concat (GGS_string (") should be inferior to duration ("))).operator_concat (var_cas_len.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (115)))).operator_concat (GGS_string (") minus the previous delay("))).operator_concat (var_cas_previous_delay.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (115)))).operator_concat (GGS_string (").")) COMMA_SOURCE_FILE_AT_LINE (116)) ;
                    }
                  }
                }else{
                }
              }
            }
            const GGS_bool cond_5765 = (var_cas_offset.substract_operation (inLexique, var_cas_previous_offset COMMA_SOURCE_FILE_AT_LINE (123))).operator_strictInf (var_cas_mc) ;
            if (cond_5765.isBuiltAndTrue ()) {
              const GGS_bool cond_5579 = var_cas_first_ep ;
              if (cond_5579.isBuiltAndTrue ()) {
                const GGS_bool cond_5560 = (var_cas_offset).operator_isNotEqual (GGS_uint64 (0ULL)) ;
                if (cond_5560.isBuiltAndTrue ()) {
                  var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("OS443 - OFFSET of first expiry point is lower than MINCYCLE of the driving counter and not equal to 0.") COMMA_SOURCE_FILE_AT_LINE (127)) ;
                }
              }else if (cond_5579.isBuiltAndFalse ()) {
                var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((GGS_string ("OS408 - Delay between expiry point number ")).operator_concat (var_cas_i.substract_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (129)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (129)))).operator_concat (GGS_string (" and "))).operator_concat (var_cas_i.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (129)))).operator_concat (GGS_string (" is lower than MINCYCLE of the driving counter")) COMMA_SOURCE_FILE_AT_LINE (130)) ;
              }
            }
            const GGS_bool cond_6174 = (var_cas_offset.substract_operation (inLexique, var_cas_previous_offset COMMA_SOURCE_FILE_AT_LINE (132))).operator_strictSup (var_cas_mav) ;
            if (cond_6174.isBuiltAndTrue ()) {
              const GGS_bool cond_5984 = var_cas_first_ep ;
              if (cond_5984.isBuiltAndTrue ()) {
                var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("OS443 - OFFSET of first expiry point is greater than MAXALLOWEDVALUE of the driving counter") COMMA_SOURCE_FILE_AT_LINE (135)) ;
              }else if (cond_5984.isBuiltAndFalse ()) {
                var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((GGS_string ("OS408 - Delay between expiry point number ")).operator_concat (var_cas_i.substract_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (136)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (136)))).operator_concat (GGS_string (" and "))).operator_concat (var_cas_i.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (136)))).operator_concat (GGS_string (" is greater than MAXALLOWEDVALUE of the driving counter")) COMMA_SOURCE_FILE_AT_LINE (137)) ;
              }
            }
            var_cas_first_ep = GGS_bool (false) ;
            var_cas_previous_offset = var_cas_offset ;
            const GGS_bool cond_7994 = (var_cas_i).operator_isEqual (var_cas_exp_pt_number) ;
            if (cond_7994.isBuiltAndTrue ()) {
              { const GGS_adjustable_obj _var_7212 = operand_3023->point.reader_adjust (inLexique COMMA_SOURCE_FILE_AT_LINE (145)) ; // CAST instruction
                if (_var_7212.getPtr () != NULL) {
                  macroValidPointer (_var_7212.getPtr ()) ;
                  if (typeid (cPtr_adjustable_true) == typeid (* (_var_7212.getPtr ()))) {
                    var_cas_last_delay = var_cas_len.substract_operation (inLexique, var_cas_previous_offset COMMA_SOURCE_FILE_AT_LINE (147)).add_operation (inLexique, var_cas_first_delay COMMA_SOURCE_FILE_AT_LINE (147)) ;
                    const GGS_bool cond_6896 = (var_cas_first_maxret).operator_strictSup (var_cas_last_delay.substract_operation (inLexique, var_cas_mc COMMA_SOURCE_FILE_AT_LINE (148))) ;
                    if (cond_6896.isBuiltAndTrue ()) {
                      operand_502->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((((GGS_string ("OS436 - In first expiry point, MaxRetard (")).operator_concat (var_cas_first_maxret.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (149)))).operator_concat (GGS_string (") should be inferior to the previous delay ("))).operator_concat (var_cas_last_delay.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (149)))).operator_concat (GGS_string (") minus MINCYCLE of the counter ("))).operator_concat (var_cas_mc.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (149)))).operator_concat (GGS_string (").")) COMMA_SOURCE_FILE_AT_LINE (150)) ;
                    }
                    const GGS_bool cond_7186 = (var_cas_first_maxadv).operator_strictSup (var_cas_len.substract_operation (inLexique, var_cas_first_delay COMMA_SOURCE_FILE_AT_LINE (151))) ;
                    if (cond_7186.isBuiltAndTrue ()) {
                      operand_502->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((((((GGS_string ("OS437 - In first expiry point, MaxAdvance (")).operator_concat (var_cas_first_maxadv.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (152)))).operator_concat (GGS_string (") should be inferior to duration ("))).operator_concat (var_cas_len.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (152)))).operator_concat (GGS_string (") minus the first delay("))).operator_concat (var_cas_first_delay.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (152)))).operator_concat (GGS_string (").")) COMMA_SOURCE_FILE_AT_LINE (153)) ;
                    }
                  }else{
                  }
                }
              }
              GGS_uint64  var_cas_final_delay = var_cas_len.substract_operation (inLexique, var_cas_previous_offset COMMA_SOURCE_FILE_AT_LINE (156)) ;
              const GGS_bool cond_7742 = (var_cas_final_delay).operator_isEqual (GGS_uint64 (0ULL)) ;
              if (cond_7742.isBuiltAndTrue ()) {
                const GGS_bool cond_7722 = var_cas_perio ;
                if (cond_7722.isBuiltAndTrue ()) {
                  var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS427 - Final delay can be equal to 0 only for single-shot schedule table and ")).operator_concat (operand_502->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (162)))).operator_concat (GGS_string (" is a repeating one")) COMMA_SOURCE_FILE_AT_LINE (163)) ;
                }
              }else if (cond_7742.isBuiltAndFalse ()) {
                const GGS_bool cond_7952 = ((var_cas_final_delay).operator_strictInf (var_cas_mc)).operator_or ((var_cas_final_delay).operator_strictSup (var_cas_mav)) ;
                if (cond_7952.isBuiltAndTrue ()) {
                  var_cas_off_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("OS444 - Final delay should be within MINCYCLE and MAXALLOWEDVALUE of the driving counter") COMMA_SOURCE_FILE_AT_LINE (167)) ;
                }
              }
            }
          }
        }
        { const GGS_ltgt_sync_obj _var_9289 = operand_502->mInfo.st.reader_ltgt_sync (inLexique COMMA_SOURCE_FILE_AT_LINE (175)) ; // CAST instruction
          if (_var_9289.getPtr () != NULL) {
            macroValidPointer (_var_9289.getPtr ()) ;
            if (typeid (cPtr_ltgt_sync_true) == typeid (* (_var_9289.getPtr ()))) {
              const GGS_ltgt_sync_true var_cas_sst (_var_9289.getPtr ()) ;
              const GGS_bool cond_8962 = (var_cas_sst.reader_strategy (inLexique COMMA_SOURCE_FILE_AT_LINE (177)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (177))).operator_isEqual (GGS_string ("IMPLICIT")) ;
              if (cond_8962.isBuiltAndTrue ()) {
                { const GGS_autostart_obj _var_8698 = operand_502->mInfo.st.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (178)) ; // CAST instruction
                  if (_var_8698.getPtr () != NULL) {
                    macroValidPointer (_var_8698.getPtr ()) ;
                    if (typeid (cPtr_sd_autostart_relative) == typeid (* (_var_8698.getPtr ()))) {
                      operand_502->mInfo.st.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (180)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (180)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("OS430 - An IMPLICIT schedule table should be started in Absolute mode only") COMMA_SOURCE_FILE_AT_LINE (181)) ;
                    }else if (typeid (cPtr_sd_autostart_synchron) == typeid (* (_var_8698.getPtr ()))) {
                      operand_502->mInfo.st.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (182)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (182)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("OS430 - An IMPLICIT schedule table should be started in Absolute mode only") COMMA_SOURCE_FILE_AT_LINE (183)) ;
                    }else{
                    }
                  }
                }
                const GGS_bool cond_8945 = (var_cas_len).operator_isNotEqual (var_cas_mav.add_operation (inLexique, GGS_uint64 (1ULL) COMMA_SOURCE_FILE_AT_LINE (185))) ;
                if (cond_8945.isBuiltAndTrue ()) {
                  operand_502->mInfo.st.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (186)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (186)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS429 - An IMPLICIT schedule table should have a duration equal to OSMAXALLOWEDVALUE + 1 (")).operator_concat (var_cas_mav.add_operation (inLexique, GGS_uint64 (1ULL) COMMA_SOURCE_FILE_AT_LINE (186)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (186)))).operator_concat (GGS_string (") of its counter.")) COMMA_SOURCE_FILE_AT_LINE (187)) ;
                }
              }
              const GGS_bool cond_9270 = (var_cas_sst.reader_strategy (inLexique COMMA_SOURCE_FILE_AT_LINE (189)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (189))).operator_isEqual (GGS_string ("EXPLICIT")) ;
              if (cond_9270.isBuiltAndTrue ()) {
                const GGS_bool cond_9253 = (var_cas_len).operator_strictSup (var_cas_mav.add_operation (inLexique, GGS_uint64 (1ULL) COMMA_SOURCE_FILE_AT_LINE (190))) ;
                if (cond_9253.isBuiltAndTrue ()) {
                  operand_502->mInfo.st.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (191)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (191)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS431 - An EXPLICIT schedule table shouldn't have a duration greater than OSMAXALLOWEVALUE + 1 (")).operator_concat (var_cas_mav.add_operation (inLexique, GGS_uint64 (1ULL) COMMA_SOURCE_FILE_AT_LINE (191)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (191)))).operator_concat (GGS_string (") of its counter.")) COMMA_SOURCE_FILE_AT_LINE (192)) ;
                }
              }
            }else{
            }
          }
        }
        { const GGS_autostart_obj _var_10238 = operand_502->mInfo.st.reader_autostart (inLexique COMMA_SOURCE_FILE_AT_LINE (198)) ; // CAST instruction
          if (_var_10238.getPtr () != NULL) {
            macroValidPointer (_var_10238.getPtr ()) ;
            if (typeid (cPtr_sd_autostart_relative) == typeid (* (_var_10238.getPtr ()))) {
              const GGS_sd_autostart_relative var_cas_relative_data (_var_10238.getPtr ()) ;
              const GGS_bool cond_9730 = (var_cas_relative_data.reader_offset (inLexique COMMA_SOURCE_FILE_AT_LINE (200)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (200))).operator_isEqual (GGS_uint64 (0ULL)) ;
              if (cond_9730.isBuiltAndTrue ()) {
                operand_502->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS332 - ")).operator_concat (operand_502->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (201)))).operator_concat (GGS_string (" autostart's offset is equal to 0.")) COMMA_SOURCE_FILE_AT_LINE (202)) ;
              }else if (cond_9730.isBuiltAndFalse ()) {
                const GGS_bool cond_9961 = (var_cas_relative_data.reader_offset (inLexique COMMA_SOURCE_FILE_AT_LINE (202)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (202))).operator_strictSup (var_cas_mav.substract_operation (inLexique, var_cas_first_delay COMMA_SOURCE_FILE_AT_LINE (202))) ;
                if (cond_9961.isBuiltAndTrue ()) {
                  operand_502->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS276 - ")).operator_concat (operand_502->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (203)))).operator_concat (GGS_string (" autostart's offset is greater than MAXALLOWEDVALUE of the driving counter minus the Initial Offset.")) COMMA_SOURCE_FILE_AT_LINE (204)) ;
                }
              }
            }else if (typeid (cPtr_sd_autostart_absolute) == typeid (* (_var_10238.getPtr ()))) {
              const GGS_sd_autostart_absolute var_cas_absolute_data (_var_10238.getPtr ()) ;
              const GGS_bool cond_10219 = (var_cas_absolute_data.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (206)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (206))).operator_strictSup (var_cas_mav) ;
              if (cond_10219.isBuiltAndTrue ()) {
                operand_502->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS349 - ")).operator_concat (operand_502->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (207)))).operator_concat (GGS_string (" autostart's offset is greater than MAXALLOWEDVALUE of the driving counter.")) COMMA_SOURCE_FILE_AT_LINE (208)) ;
              }
            }else{
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_schedule_tables_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//Implementation of routine "schedule_tables_counters_exist_and_compatible"  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_schedule_tables_counters_exist_and_compatible (C_Compiler & inLexique,
                                const GGS_scheduletable_map   var_cas_sts,
                                const GGS_counter_map   var_cas_cnts COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_schedule_tables_counters_exist_and_compatible at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_scheduletable_map::cEnumerator enumerator_10415 (var_cas_sts, true) ;
    const GGS_scheduletable_map::cElement * operand_10415 = NULL ;
    while (((operand_10415 = enumerator_10415.nextObject ()))) {
      macroValidPointer (operand_10415) ;
      GGS_lstring  var_cas_cnt = operand_10415->mInfo.st.reader_counter (inLexique COMMA_SOURCE_FILE_AT_LINE (220)) ;
      const GGS_bool cond_10659 = ((var_cas_cnts.reader_hasKey (var_cas_cnt.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (222)))).operator_not ()).operator_and ((var_cas_cnt.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (222))).operator_isNotEqual (GGS_string ("SystemCounter"))) ;
      if (cond_10659.isBuiltAndTrue ()) {
        var_cas_cnt.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS409 - Counter is not defined in ")).operator_concat (operand_10415->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (223)))).operator_concat (GGS_string (" !")) COMMA_SOURCE_FILE_AT_LINE (224)) ;
      }else if (cond_10659.isBuiltAndFalse ()) {
        GGS_uint64  var_cas_len = GGS_uint64 (0ULL) ;
        GGS_location  var_cas_loc = GGS_location (inLexique) ;
        { const GGS_basic_type _var_10935 = operand_10415->mInfo.st.reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (227)) ; // CAST instruction
          if (_var_10935.getPtr () != NULL) {
            macroValidPointer (_var_10935.getPtr ()) ;
            if (typeid (cPtr_uint64_class) == typeid (* (_var_10935.getPtr ()))) {
              const GGS_uint64_class var_cas_ui (_var_10935.getPtr ()) ;
              var_cas_len = var_cas_ui.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (228)) ;
              var_cas_loc = var_cas_ui.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (228)) ;
            }else{
              GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("Internal error, incorrect datatype for LENGTH attribute of schedule table ")).operator_concat (operand_10415->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (229))) COMMA_SOURCE_FILE_AT_LINE (230)) ;
            }
          }
        }
        GGS_counter_obj  var_cas_cpt ;
        const GGS_counter_map  temp_11100 = var_cas_cnts ;
        if (temp_11100.isBuilt ()) {
          temp_11100 (HERE)->method_getCounter (inLexique, var_cas_cnt, var_cas_cpt COMMA_SOURCE_FILE_AT_LINE (235)) ;
        }
        GGS_uint64  var_cas_max = GGS_uint64 (0ULL) ;
        { const GGS_basic_type _var_11384 = var_cas_cpt.reader_max_allowed_value (inLexique COMMA_SOURCE_FILE_AT_LINE (238)) ; // CAST instruction
          if (_var_11384.getPtr () != NULL) {
            macroValidPointer (_var_11384.getPtr ()) ;
            if (typeid (cPtr_uint32_class) == typeid (* (_var_11384.getPtr ()))) {
              const GGS_uint32_class var_cas_ui (_var_11384.getPtr ()) ;
              var_cas_max = var_cas_ui.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (240)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (240)) ;
            }else{
              GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("Internal error, incorrect datatype for MAXALLOWEDVALUE attribute of counter ")).operator_concat (var_cas_cnt.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (242))) COMMA_SOURCE_FILE_AT_LINE (243)) ;
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_schedule_tables_counters_exist_and_compatible\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//    Implementation of routine "schedule_tables_tasks_and_events_exist"     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_schedule_tables_tasks_and_events_exist (C_Compiler & inLexique,
                                const GGS_root_obj   var_cas_cpu,
                                GGS_task_map   var_cas_tasks COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_schedule_tables_tasks_and_events_exist at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_scheduletable_map::cEnumerator enumerator_11586 (var_cas_cpu.reader_scheduletables (inLexique COMMA_SOURCE_FILE_AT_LINE (256)), true) ;
    const GGS_scheduletable_map::cElement * operand_11586 = NULL ;
    while (((operand_11586 = enumerator_11586.nextObject ()))) {
      macroValidPointer (operand_11586) ;
      {
        GGS_expiry_point_list::cEnumerator enumerator_11662 (operand_11586->mInfo.st.reader_exp_points (inLexique COMMA_SOURCE_FILE_AT_LINE (257)), true) ;
        const GGS_expiry_point_list::cElement * operand_11662 = NULL ;
        while (((operand_11662 = enumerator_11662.nextObject ()))) {
          macroValidPointer (operand_11662) ;
          GGS_lstring  var_cas_ep_name = operand_11662->point.reader_name (inLexique COMMA_SOURCE_FILE_AT_LINE (258)) ;
          {
            GGS_action_list::cEnumerator enumerator_11735 (operand_11662->point.reader_actions (inLexique COMMA_SOURCE_FILE_AT_LINE (259)), true) ;
            const GGS_action_list::cElement * operand_11735 = NULL ;
            while (((operand_11735 = enumerator_11735.nextObject ()))) {
              macroValidPointer (operand_11735) ;
              { const GGS_action_obj _var_12944 = operand_11735->action ; // CAST instruction
                if (_var_12944.getPtr () != NULL) {
                  macroValidPointer (_var_12944.getPtr ()) ;
                  if (typeid (cPtr_activatetask_action) == typeid (* (_var_12944.getPtr ()))) {
                    const GGS_activatetask_action var_cas_ata (_var_12944.getPtr ()) ;
                    const GGS_bool cond_12001 = (var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (262)).reader_hasKey (var_cas_ata.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (262)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (262)))).operator_not () ;
                    if (cond_12001.isBuiltAndTrue ()) {
                      operand_11735->action.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (263)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TASK attribute of action does not reference an existing task") COMMA_SOURCE_FILE_AT_LINE (264)) ;
                    }
                  }else if (typeid (cPtr_setevent_action) == typeid (* (_var_12944.getPtr ()))) {
                    const GGS_setevent_action var_cas_sea (_var_12944.getPtr ()) ;
                    const GGS_bool cond_12229 = (var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (266)).reader_hasKey (var_cas_sea.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (266)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (266)))).operator_not () ;
                    if (cond_12229.isBuiltAndTrue ()) {
                      operand_11735->action.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (267)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("TASK attribute of action does not reference an existing task") COMMA_SOURCE_FILE_AT_LINE (268)) ;
                    }
                    GGS_task_obj  var_cas_task_data ;
                    GGS_lstringlist  var_cas_known_events ;
                    const GGS_task_map  temp_12322 = var_cas_tasks ;
                    if (temp_12322.isBuilt ()) {
                      temp_12322 (HERE)->method_get (inLexique, var_cas_sea.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (271)), var_cas_task_data COMMA_SOURCE_FILE_AT_LINE (271)) ;
                    }
                    var_cas_known_events = var_cas_task_data.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (272)) ;
                    const GGS_bool cond_12605 = (var_cas_known_events.reader_length ()).operator_isEqual (GGS_uint (0U)) ;
                    if (cond_12605.isBuiltAndTrue ()) {
                      var_cas_sea.reader_event_name (inLexique COMMA_SOURCE_FILE_AT_LINE (274)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("An action can't set an Event to a basic task (Task ")).operator_concat (var_cas_sea.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (274)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (274)))).operator_concat (GGS_string (" is a basic task).")) COMMA_SOURCE_FILE_AT_LINE (275)) ;
                    }
                    const GGS_bool cond_12797 = (var_cas_cpu.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (276)).reader_hasKey (var_cas_sea.reader_event_name (inLexique COMMA_SOURCE_FILE_AT_LINE (276)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (276)))).operator_not () ;
                    if (cond_12797.isBuiltAndTrue ()) {
                      operand_11735->action.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (277)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("EVENT attribute of action does not reference an existing event") COMMA_SOURCE_FILE_AT_LINE (278)) ;
                    }
                  }else{
                    var_cas_ep_name.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("Internal error, incorrect datatype for ACTION attribute of expiry point ")).operator_concat (var_cas_ep_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (280))) COMMA_SOURCE_FILE_AT_LINE (281)) ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_schedule_tables_tasks_and_events_exist\n") ;
  #endif
}

//---------------------------------------------------------------------------*

