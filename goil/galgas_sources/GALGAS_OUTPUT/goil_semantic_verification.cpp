//---------------------------------------------------------------------------*
//                                                                           *
//                  File 'goil_semantic_verification.cpp'                    *
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
#include "goil_semantic_verification.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_semantic_verification.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "counters_well_formed"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_counters_well_formed (C_Compiler & inLexique,
                                const GGS_counter_map   var_cas_counters COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_counters_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_counter_map::cEnumerator enumerator_1018 (var_cas_counters, true) ;
    const GGS_counter_map::cElement * operand_1018 = NULL ;
    while (((operand_1018 = enumerator_1018.nextObject ()))) {
      macroValidPointer (operand_1018) ;
      { const GGS_basic_type _var_1263 = operand_1018->mInfo.counter.reader_max_allowed_value (inLexique COMMA_SOURCE_FILE_AT_LINE (35)) ; // CAST instruction
        if (_var_1263.getPtr () != NULL) {
          macroValidPointer (_var_1263.getPtr ()) ;
          if (typeid (cPtr_void) == typeid (* (_var_1263.getPtr ()))) {
            operand_1018->mKey.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (37)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("MAXALLOWEDVALUE attribute not defined for COUNTER ")).operator_concat (operand_1018->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (37))) COMMA_SOURCE_FILE_AT_LINE (38)) ;
          }else{
          }
        }
      }
      { const GGS_basic_type _var_1460 = operand_1018->mInfo.counter.reader_ticks_per_base (inLexique COMMA_SOURCE_FILE_AT_LINE (41)) ; // CAST instruction
        if (_var_1460.getPtr () != NULL) {
          macroValidPointer (_var_1460.getPtr ()) ;
          if (typeid (cPtr_void) == typeid (* (_var_1460.getPtr ()))) {
            operand_1018->mKey.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (43)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("TICKSPERBASE attribute not defined for COUNTER ")).operator_concat (operand_1018->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (43))) COMMA_SOURCE_FILE_AT_LINE (44)) ;
          }else{
          }
        }
      }
      { const GGS_basic_type _var_1648 = operand_1018->mInfo.counter.reader_min_cycle (inLexique COMMA_SOURCE_FILE_AT_LINE (47)) ; // CAST instruction
        if (_var_1648.getPtr () != NULL) {
          macroValidPointer (_var_1648.getPtr ()) ;
          if (typeid (cPtr_void) == typeid (* (_var_1648.getPtr ()))) {
            operand_1018->mKey.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (49)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("MINCYCLE attribute not defined for COUNTER ")).operator_concat (operand_1018->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (49))) COMMA_SOURCE_FILE_AT_LINE (50)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_counters_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "alarms_well_formed"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_alarms_well_formed (C_Compiler & inLexique,
                                const GGS_alarm_map   var_cas_alarms COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_alarms_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_alarm_map::cEnumerator enumerator_1962 (var_cas_alarms, true) ;
    const GGS_alarm_map::cElement * operand_1962 = NULL ;
    while (((operand_1962 = enumerator_1962.nextObject ()))) {
      macroValidPointer (operand_1962) ;
      const GGS_bool cond_2149 = (operand_1962->mInfo.alarm.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (73)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (73))).operator_isEqual (GGS_string ("")) ;
      if (cond_2149.isBuiltAndTrue ()) {
        operand_1962->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("COUNTER attribute undefined for ALARM ")).operator_concat (operand_1962->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (74))) COMMA_SOURCE_FILE_AT_LINE (75)) ;
      }
      { const GGS_action_obj _var_2322 = operand_1962->mInfo.alarm.reader_action_params (inLexique COMMA_SOURCE_FILE_AT_LINE (77)) ; // CAST instruction
        if (_var_2322.getPtr () != NULL) {
          macroValidPointer (_var_2322.getPtr ()) ;
          if (typeid (cPtr_void_action) == typeid (* (_var_2322.getPtr ()))) {
            operand_1962->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("ACTION attribute undefined for ALARM ")).operator_concat (operand_1962->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (79))) COMMA_SOURCE_FILE_AT_LINE (80)) ;
          }else{
          }
        }
      }
      { const GGS_autostart_obj _var_2498 = operand_1962->mInfo.alarm.reader_autostart_params (inLexique COMMA_SOURCE_FILE_AT_LINE (83)) ; // CAST instruction
        if (_var_2498.getPtr () != NULL) {
          macroValidPointer (_var_2498.getPtr ()) ;
          if (typeid (cPtr_autostart_void) == typeid (* (_var_2498.getPtr ()))) {
            operand_1962->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("AUTOSTART attribute undefined for ALARM ")).operator_concat (operand_1962->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (85))) COMMA_SOURCE_FILE_AT_LINE (86)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_alarms_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "events_well_formed"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_events_well_formed (C_Compiler & inLexique,
                                const GGS_event_map   var_cas_events COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_events_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_event_map::cEnumerator enumerator_2777 (var_cas_events, true) ;
    const GGS_event_map::cElement * operand_2777 = NULL ;
    while (((operand_2777 = enumerator_2777.nextObject ()))) {
      macroValidPointer (operand_2777) ;
      { const GGS_event_mask_obj _var_3056 = operand_2777->mInfo.event.reader_mask (inLexique COMMA_SOURCE_FILE_AT_LINE (106)) ; // CAST instruction
        if (_var_3056.getPtr () != NULL) {
          macroValidPointer (_var_3056.getPtr ()) ;
          if (typeid (cPtr_event_mask_void_obj) == typeid (* (_var_3056.getPtr ()))) {
            const GGS_event_mask_void_obj var_cas_mask (_var_3056.getPtr ()) ;
            operand_2777->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("MASK attribute undefined for EVENT ")).operator_concat (operand_2777->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (108))) COMMA_SOURCE_FILE_AT_LINE (109)) ;
            var_cas_mask.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (109)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was previously defined here") COMMA_SOURCE_FILE_AT_LINE (110)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_events_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//Implementation of routine "all_events_and_resources_and_messages_defined_and_used"*
//                                                                           *
//---------------------------------------------------------------------------*

void routine_all_events_and_resources_and_messages_defined_and_used (C_Compiler & inLexique,
                                const GGS_root_obj   var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_all_events_and_resources_and_messages_defined_and_used at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_task_map  var_cas_tasks = var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (119)) ;
  GGS_isr_map  var_cas_isrs = var_cas_cpu.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (120)) ;
  GGS_event_map  var_cas_events = var_cas_cpu.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (121)) ;
  GGS_resource_map  var_cas_resources = var_cas_cpu.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (122)) ;
  GGS_message_map  var_cas_messages = var_cas_cpu.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (123)) ;
  GGS_stringset  var_cas_used_events = GGS_stringset ::constructor_emptySet () ;
  GGS_stringset  var_cas_used_resources = GGS_stringset ::constructor_emptySet () ;
  GGS_stringset  var_cas_used_messages = GGS_stringset ::constructor_emptySet () ;
  {
    GGS_task_map::cEnumerator enumerator_3572 (var_cas_tasks, true) ;
    const GGS_task_map::cElement * operand_3572 = NULL ;
    while (((operand_3572 = enumerator_3572.nextObject ()))) {
      macroValidPointer (operand_3572) ;
      GGS_lstringlist  var_cas_task_events ;
      var_cas_task_events = operand_3572->mInfo.task.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (133)) ;
      {
        GGS_lstringlist::cEnumerator enumerator_3742 (var_cas_task_events, true) ;
        const GGS_lstringlist::cElement * operand_3742 = NULL ;
        while (((operand_3742 = enumerator_3742.nextObject ()))) {
          macroValidPointer (operand_3742) ;
          var_cas_used_events.addAssign_operation (operand_3742->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (135))) ;
          const GGS_bool cond_3949 = (var_cas_events.reader_hasKey (operand_3742->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (136)))).operator_not () ;
          if (cond_3949.isBuiltAndTrue ()) {
            operand_3742->mValue.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("EVENT ")).operator_concat (operand_3742->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (137)))).operator_concat (GGS_string (" is not defined")) COMMA_SOURCE_FILE_AT_LINE (138)) ;
          }
        }
      }
      GGS_lstringlist  var_cas_task_resources ;
      var_cas_task_resources = operand_3572->mInfo.task.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (143)) ;
      {
        GGS_lstringlist::cEnumerator enumerator_4116 (var_cas_task_resources, true) ;
        const GGS_lstringlist::cElement * operand_4116 = NULL ;
        while (((operand_4116 = enumerator_4116.nextObject ()))) {
          macroValidPointer (operand_4116) ;
          var_cas_used_resources.addAssign_operation (operand_4116->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (145))) ;
          const GGS_bool cond_4322 = (var_cas_resources.reader_hasKey (operand_4116->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (146)))).operator_not () ;
          if (cond_4322.isBuiltAndTrue ()) {
            operand_4116->mValue.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("RESOURCE ")).operator_concat (operand_4116->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (147)))).operator_concat (GGS_string (" is not defined")) COMMA_SOURCE_FILE_AT_LINE (148)) ;
          }
        }
      }
      GGS_lstringlist  var_cas_task_messages ;
      var_cas_task_messages = operand_3572->mInfo.task.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (153)) ;
      {
        GGS_lstringlist::cEnumerator enumerator_4484 (var_cas_task_messages, true) ;
        const GGS_lstringlist::cElement * operand_4484 = NULL ;
        while (((operand_4484 = enumerator_4484.nextObject ()))) {
          macroValidPointer (operand_4484) ;
          var_cas_used_messages.addAssign_operation (operand_4484->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (155))) ;
          const GGS_bool cond_4694 = (var_cas_messages.reader_hasKey (operand_4484->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (156)))).operator_not () ;
          if (cond_4694.isBuiltAndTrue ()) {
            operand_4484->mValue.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("MESSAGE ")).operator_concat (operand_4484->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (157)))).operator_concat (GGS_string (" is not defined")) COMMA_SOURCE_FILE_AT_LINE (158)) ;
          }
        }
      }
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_4806 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_4806 = NULL ;
    while (((operand_4806 = enumerator_4806.nextObject ()))) {
      macroValidPointer (operand_4806) ;
      GGS_lstringlist  var_cas_isr_resources = operand_4806->mInfo.isr.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (166)) ;
      {
        GGS_lstringlist::cEnumerator enumerator_4965 (var_cas_isr_resources, true) ;
        const GGS_lstringlist::cElement * operand_4965 = NULL ;
        while (((operand_4965 = enumerator_4965.nextObject ()))) {
          macroValidPointer (operand_4965) ;
          var_cas_used_resources.addAssign_operation (operand_4965->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (168))) ;
          const GGS_bool cond_5164 = (var_cas_resources.reader_hasKey (operand_4965->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (169)))).operator_not () ;
          if (cond_5164.isBuiltAndTrue ()) {
            operand_4806->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("RESOURCE ")).operator_concat (operand_4965->mValue)).operator_concat (GGS_string (" is not defined")) COMMA_SOURCE_FILE_AT_LINE (171)) ;
          }
        }
      }
      GGS_lstringlist  var_cas_isr_messages ;
      var_cas_isr_messages = operand_4806->mInfo.isr.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (176)) ;
      {
        GGS_lstringlist::cEnumerator enumerator_5322 (var_cas_isr_messages, true) ;
        const GGS_lstringlist::cElement * operand_5322 = NULL ;
        while (((operand_5322 = enumerator_5322.nextObject ()))) {
          macroValidPointer (operand_5322) ;
          var_cas_used_messages.addAssign_operation (operand_5322->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (178))) ;
          const GGS_bool cond_5522 = (var_cas_messages.reader_hasKey (operand_5322->mValue.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (179)))).operator_not () ;
          if (cond_5522.isBuiltAndTrue ()) {
            operand_4806->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("MESSAGE ")).operator_concat (operand_5322->mValue)).operator_concat (GGS_string (" is not defined")) COMMA_SOURCE_FILE_AT_LINE (181)) ;
          }
        }
      }
    }
  }
  {
    GGS_event_map::cEnumerator enumerator_5630 (var_cas_events, true) ;
    const GGS_event_map::cElement * operand_5630 = NULL ;
    while (((operand_5630 = enumerator_5630.nextObject ()))) {
      macroValidPointer (operand_5630) ;
      const GGS_bool cond_5806 = (var_cas_used_events.reader_hasKey (operand_5630->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (188)))).operator_not () ;
      if (cond_5806.isBuiltAndTrue ()) {
        operand_5630->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("EVENT ")).operator_concat (operand_5630->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (189)))).operator_concat (GGS_string (" is defined but never used")) COMMA_SOURCE_FILE_AT_LINE (189)) ;
      }
    }
  }
  {
    GGS_resource_map::cEnumerator enumerator_5912 (var_cas_resources, true) ;
    const GGS_resource_map::cElement * operand_5912 = NULL ;
    while (((operand_5912 = enumerator_5912.nextObject ()))) {
      macroValidPointer (operand_5912) ;
      const GGS_bool cond_6086 = (var_cas_used_resources.reader_hasKey (operand_5912->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (195)))).operator_not () ;
      if (cond_6086.isBuiltAndTrue ()) {
        operand_5912->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("RESOURCE ")).operator_concat (operand_5912->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (196)))).operator_concat (GGS_string (" is defined but never used")) COMMA_SOURCE_FILE_AT_LINE (196)) ;
      }
    }
  }
  {
    GGS_message_map::cEnumerator enumerator_6190 (var_cas_messages, true) ;
    const GGS_message_map::cElement * operand_6190 = NULL ;
    while (((operand_6190 = enumerator_6190.nextObject ()))) {
      macroValidPointer (operand_6190) ;
      const GGS_bool cond_6366 = (var_cas_used_messages.reader_hasKey (operand_6190->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (202)))).operator_not () ;
      if (cond_6366.isBuiltAndTrue ()) {
        operand_6190->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("MESSAGE ")).operator_concat (operand_6190->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (203)))).operator_concat (GGS_string (" is defined but never used")) COMMA_SOURCE_FILE_AT_LINE (203)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_all_events_and_resources_and_messages_defined_and_used\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "all_event_masks_different"            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_all_event_masks_different (C_Compiler & inLexique,
                                GGS_event_map   var_cas_events COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_all_event_masks_different at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_stringset  var_cas_defined_masks = GGS_stringset ::constructor_emptySet () ;
  {
    GGS_event_map::cEnumerator enumerator_6520 (var_cas_events, true) ;
    const GGS_event_map::cElement * operand_6520 = NULL ;
    while (((operand_6520 = enumerator_6520.nextObject ()))) {
      macroValidPointer (operand_6520) ;
      GGS_event_mask_obj  var_cas_mask ;
      var_cas_mask = operand_6520->mInfo.event.reader_mask (inLexique COMMA_SOURCE_FILE_AT_LINE (215)) ;
      { const GGS_event_mask_obj _var_6947 = var_cas_mask ; // CAST instruction
        if (_var_6947.getPtr () != NULL) {
          macroValidPointer (_var_6947.getPtr ()) ;
          if (typeid (cPtr_event_mask_user_obj) == typeid (* (_var_6947.getPtr ()))) {
            const GGS_event_mask_user_obj var_cas_m (_var_6947.getPtr ()) ;
            GGS_string var_cas_mask_in_string = var_cas_m.reader_mask (inLexique COMMA_SOURCE_FILE_AT_LINE (218)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (218)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (218)) ;
            const GGS_bool cond_6868 = var_cas_defined_masks.reader_hasKey (var_cas_mask_in_string) ;
            if (cond_6868.isBuiltAndTrue ()) {
              operand_6520->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, ((GGS_string ("Mask ")).operator_concat (var_cas_mask_in_string)).operator_concat (GGS_string (" already used")) COMMA_SOURCE_FILE_AT_LINE (220)) ;
            }else if (cond_6868.isBuiltAndFalse ()) {
              var_cas_defined_masks.addAssign_operation (var_cas_mask_in_string) ;
            }
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_all_event_masks_different\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "all_alarm_actions_correct"            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_all_alarm_actions_correct (C_Compiler & inLexique,
                                GGS_alarm_map   var_cas_alarms,
                                GGS_task_map   var_cas_tasks,
                                GGS_counter_map   var_cas_counters COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_all_alarm_actions_correct at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_stringset  var_cas_defined_task_names ;
  var_cas_defined_task_names = var_cas_tasks.reader_allKeys (inLexique COMMA_SOURCE_FILE_AT_LINE (236)) ;
  {
    GGS_alarm_map::cEnumerator enumerator_7183 (var_cas_alarms, true) ;
    const GGS_alarm_map::cElement * operand_7183 = NULL ;
    while (((operand_7183 = enumerator_7183.nextObject ()))) {
      macroValidPointer (operand_7183) ;
      GGS_action_obj  var_cas_alarm_action ;
      var_cas_alarm_action = operand_7183->mInfo.alarm.reader_action_params (inLexique COMMA_SOURCE_FILE_AT_LINE (239)) ;
      { const GGS_action_obj _var_9038 = var_cas_alarm_action ; // CAST instruction
        if (_var_9038.getPtr () != NULL) {
          macroValidPointer (_var_9038.getPtr ()) ;
          if (typeid (cPtr_setevent_action) == typeid (* (_var_9038.getPtr ()))) {
            const GGS_setevent_action var_cas_act (_var_9038.getPtr ()) ;
            const GGS_bool cond_7542 = (var_cas_defined_task_names.reader_hasKey (var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (242)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (242)))).operator_not () ;
            if (cond_7542.isBuiltAndTrue ()) {
              var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (243)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("TASK ")).operator_concat (var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (243)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (243)))).operator_concat (GGS_string (" is never defined")) COMMA_SOURCE_FILE_AT_LINE (244)) ;
            }else if (cond_7542.isBuiltAndFalse ()) {
              GGS_task_obj  var_cas_task_data ;
              GGS_lstringlist  var_cas_known_events ;
              const GGS_task_map  temp_7632 = var_cas_tasks ;
              if (temp_7632.isBuilt ()) {
                temp_7632 (HERE)->method_get (inLexique, var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (247)), var_cas_task_data COMMA_SOURCE_FILE_AT_LINE (247)) ;
              }
              var_cas_known_events = var_cas_task_data.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (248)) ;
              const GGS_bool cond_7914 = (var_cas_known_events.reader_length ()).operator_isEqual (GGS_uint (0U)) ;
              if (cond_7914.isBuiltAndTrue ()) {
                var_cas_act.reader_event_name (inLexique COMMA_SOURCE_FILE_AT_LINE (250)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("An alarm can't set an Event to a basic task (Task ")).operator_concat (var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (250)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (250)))).operator_concat (GGS_string (" is a basic task).")) COMMA_SOURCE_FILE_AT_LINE (251)) ;
              }
            }
          }else if (typeid (cPtr_activatetask_action) == typeid (* (_var_9038.getPtr ()))) {
            const GGS_activatetask_action var_cas_act (_var_9038.getPtr ()) ;
            const GGS_bool cond_8417 = (var_cas_defined_task_names.reader_hasKey (var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (259)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (259)))).operator_not () ;
            if (cond_8417.isBuiltAndTrue ()) {
              var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (260)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("TASK ")).operator_concat (var_cas_act.reader_task_name (inLexique COMMA_SOURCE_FILE_AT_LINE (260)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (260)))).operator_concat (GGS_string (" is not defined")) COMMA_SOURCE_FILE_AT_LINE (261)) ;
            }
          }else if (typeid (cPtr_incrementcounter_action) == typeid (* (_var_9038.getPtr ()))) {
            const GGS_incrementcounter_action var_cas_act (_var_9038.getPtr ()) ;
            const GGS_bool cond_8895 = var_cas_counters.reader_hasKey (var_cas_act.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (263)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (263))) ;
            if (cond_8895.isBuiltAndTrue ()) {
              GGS_counter_obj  var_cas_cnt ;
              const GGS_counter_map  temp_8589 = var_cas_counters ;
              if (temp_8589.isBuilt ()) {
                temp_8589 (HERE)->method_getCounter (inLexique, var_cas_act.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (265)), var_cas_cnt COMMA_SOURCE_FILE_AT_LINE (265)) ;
              }
              { const GGS_counter_type _var_8876 = var_cas_cnt.reader_type (inLexique COMMA_SOURCE_FILE_AT_LINE (266)) ; // CAST instruction
                if (_var_8876.getPtr () != NULL) {
                  macroValidPointer (_var_8876.getPtr ()) ;
                  if (typeid (cPtr_software_counter) == typeid (* (_var_8876.getPtr ()))) {
                  }else{
                    var_cas_act.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (269)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("OS285 - It is impossible to increment a hardware counter (")).operator_concat (var_cas_act.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (269)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (269)))).operator_concat (GGS_string (" is not a software counter).")) COMMA_SOURCE_FILE_AT_LINE (270)) ;
                  }
                }
              }
            }else if (cond_8895.isBuiltAndFalse ()) {
              var_cas_act.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (272)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("COUNTER ")).operator_concat (var_cas_act.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (272)).reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (272)))).operator_concat (GGS_string (" is never defined")) COMMA_SOURCE_FILE_AT_LINE (273)) ;
            }
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_all_alarm_actions_correct\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of routine "verify_all"                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_verify_all (C_Compiler & inLexique,
                                GGS_root_obj  & var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_verify_all at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  ::routine_tasks_well_formed (inLexique,  var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (289)) COMMA_SOURCE_FILE_AT_LINE (289)) ;
  ::routine_counters_well_formed (inLexique,  var_cas_cpu.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (290)) COMMA_SOURCE_FILE_AT_LINE (290)) ;
  ::routine_alarms_well_formed (inLexique,  var_cas_cpu.reader_alarms (inLexique COMMA_SOURCE_FILE_AT_LINE (291)) COMMA_SOURCE_FILE_AT_LINE (291)) ;
  ::routine_resources_well_formed (inLexique,  var_cas_cpu.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (292)) COMMA_SOURCE_FILE_AT_LINE (292)) ;
  ::routine_isrs_well_formed (inLexique,  var_cas_cpu.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (293)) COMMA_SOURCE_FILE_AT_LINE (293)) ;
  ::routine_events_well_formed (inLexique,  var_cas_cpu.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (294)) COMMA_SOURCE_FILE_AT_LINE (294)) ;
  ::routine_networkmessages_well_formed (inLexique,  var_cas_cpu.reader_net_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (295)) COMMA_SOURCE_FILE_AT_LINE (295)) ;
  GGS_resource_map  var_cas_resources = var_cas_cpu.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (304)) ;
  ::routine_resolve_linked_resources (inLexique,  var_cas_resources COMMA_SOURCE_FILE_AT_LINE (305)) ;
  var_cas_cpu.modifier_setResources (inLexique, var_cas_resources COMMA_SOURCE_FILE_AT_LINE (306)) ;
  ::routine_all_events_and_resources_and_messages_defined_and_used (inLexique,  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (308)) ;
  ::routine_all_alarm_actions_correct (inLexique,  var_cas_cpu.reader_alarms (inLexique COMMA_SOURCE_FILE_AT_LINE (310)),  var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (310)),  var_cas_cpu.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (310)) COMMA_SOURCE_FILE_AT_LINE (310)) ;
  ::routine_counters_of_alarms_defined (inLexique,  var_cas_cpu.reader_alarms (inLexique COMMA_SOURCE_FILE_AT_LINE (311)),  var_cas_cpu.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (311)) COMMA_SOURCE_FILE_AT_LINE (311)) ;
  ::routine_networkmessages_exist_and_ok (inLexique,  var_cas_cpu.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (312)),  var_cas_cpu.reader_net_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (312)) COMMA_SOURCE_FILE_AT_LINE (312)) ;
  const GGS_bool cond_10443 = gOption_goil_5F_options_autosar_5F_on.value () ;
  if (cond_10443.isBuiltAndTrue ()) {
    ::routine_schedule_tables_well_formed (inLexique,  var_cas_cpu.reader_scheduletables (inLexique COMMA_SOURCE_FILE_AT_LINE (316)),  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (316)) ;
    ::routine_schedule_tables_counters_exist_and_compatible (inLexique,  var_cas_cpu.reader_scheduletables (inLexique COMMA_SOURCE_FILE_AT_LINE (317)),  var_cas_cpu.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (317)) COMMA_SOURCE_FILE_AT_LINE (317)) ;
    ::routine_schedule_tables_tasks_and_events_exist (inLexique,  var_cas_cpu,  var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (318)) COMMA_SOURCE_FILE_AT_LINE (318)) ;
    ::routine_apps_well_formed (inLexique,  var_cas_cpu COMMA_SOURCE_FILE_AT_LINE (319)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_verify_all\n") ;
  #endif
}

//---------------------------------------------------------------------------*

