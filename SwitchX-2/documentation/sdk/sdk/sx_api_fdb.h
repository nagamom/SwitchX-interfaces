/*
 *                  - Mellanox Proprietary -
 *
 *  Copyright (C) January 2010, Mellanox Technologies Ltd.  ALL RIGHTS RESERVED.
 *
 *  Except as specifically permitted herein, no portion of the information,
 *  including but not limited to object code and source code, may be reproduced,
 *  modified, distributed, republished or otherwise exploited in any form or by
 *  any means for any purpose without the prior written permission of Mellanox
 *  Technologies Ltd. Use of software subject to the terms and conditions
 *  detailed in the file "LICENSE.txt".
 */

#ifndef __SX_API_FDB_H__
#define __SX_API_FDB_H__

#include <sx/sdk/sx_api.h>


/***********************************************
*  API functions
***********************************************/

/**
 * This API sets the log verbosity level of FDB MODULE.
 *
 * @param[in] handle                   - SX-API handle
 * @param[in] verbosity_target         - set verbosity of : API / MODULE / BOTH
 * @param[in] module_verbosity_level   - FDB module verbosity level
 * @param[in] api_verbosity_level      - FDB API verbosity level
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_log_verbosity_level_set(const sx_api_handle_t           handle,
                                               const sx_log_verbosity_target_t verbosity_target,
                                               const sx_verbosity_level_t      module_verbosity_level,
                                               const sx_verbosity_level_t      api_verbosity_level);

/**
 * This API gets the log verbosity level of FDB MODULE.
 *
 * @param[in]  handle                   - SX-API handle
 * @param[in]  verbosity_target         - get verbosity of : API / MODULE / BOTH
 * @param[out] module_verbosity_level_p - FDB module verbosity level
 * @param[out] api_verbosity_level_p    - FDB API verbosity level
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_log_verbosity_level_get(const sx_api_handle_t           handle,
                                               const sx_log_verbosity_target_t verbosity_target,
                                               sx_verbosity_level_t           *module_verbosity_level_p,
                                               sx_verbosity_level_t           *api_verbosity_level_p);

/**
 *  This function sets the FDB age time in seconds. Age time is
 *  the time after which automatically learned addresses are deleted
 *  from the FDB if they receive no traffic.
 *
 * @param[in] handle     - SX-API handle
 * @param[in] swid       - switch ID
 * @param[in] age_time   - time in seconds
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_age_time_set(const sx_api_handle_t   handle,
                                    const sx_swid_t         swid,
                                    const sx_fdb_age_time_t age_time);

/**
 *  This function retrieves the FDB age time in seconds. Age time is
 *  the time after which automatically learned addresses are deleted
 *  from the FDB if they receive no traffic.
 *
 * @param[in] handle       - SX-API handle
 * @param[in] swid         - switch ID
 * @param[out] age_time_p   - time in seconds
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_age_time_get(const sx_api_handle_t handle,
                                    const sx_swid_t       swid,
                                    sx_fdb_age_time_t    *age_time_p);

/**
 *  This function sets the FDB poll for MAC entries notifications.
 *
 * @param[in] handle   - SX-API handle
 * @param[in] swid     - virtual switch partition ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_NO_RESOURCES if there is no place in the jobs buffer
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_poll_set(const sx_api_handle_t handle,
                                const sx_swid_t       swid);

/**
 *  This function sets the FDB polling interval from HW in 0.1
 *  seconds.
 *
 * @param[in] handle      - SX-API handle
 * @param[in] swid        - virtual switch partition ID
 * @param[in] interval    - polling interval in 0.1 seconds
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_polling_interval_set(const sx_api_handle_t           handle,
                                            const sx_swid_t                 swid,
                                            const sx_fdb_polling_interval_t interval);

/**
 *  This function gets the FDB polling interval in 0.1 seconds
 *  seconds.
 *
 * @param[in] handle      - SX-API handle
 * @param[in] swid        - virtual switch partition ID
 * @param[in] interval    - polling interval in 0.1 seconds
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 * @return SX_STATUS_PARAM_NULL if parameter is NULL.
 */
sx_status_t sx_api_fdb_polling_interval_get(const sx_api_handle_t      handle,
                                            const sx_swid_t            swid,
                                            sx_fdb_polling_interval_t* interval);

/**
 *  This function adds/deletes UC MAC and UC LAG MAC entries to/from the FDB.
 *  In case the operation fails on one entry (or more), an error is returned,
 *  mac_list_p stores those entries, and their quantity is stored in data_cnt.
 *  If the operation is completed successfully, SUCCESS is returned, and
 *  data_cnt_p and mac_list_p are not changed.
 *
 *  When in 802.1D mode, instead of providing a vid(Vlan ID) or fid (filtering ID)
 *  in mac_list_p->fid_vid, you should provide a bridge_id.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] cmd               - ADD/DELETE
 * @param[in] swid              - virtual switch partition ID
 * @param[in,out] mac_list_p    - list of MAC record parameters. Upon deletion,
 *                                entry_type is DONT_CARE
 * @param[in,out] data_cnt_p    - number of MAC records to ADD/DELETE
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_NO_RESOURCES if the FDB hash bin is full
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_mac_addr_set(const sx_api_handle_t        handle,
                                       const sx_access_cmd_t        cmd,
                                       const sx_swid_t              swid,
                                       sx_fdb_uc_mac_addr_params_t *mac_list_p,
                                       uint32_t                    *data_cnt_p);

/**
 * This function reads MAC entries from the SW FDB table, which is
 * an exact copy of the HW DB on any device. The output supports up
 * to SX_FDB_MAX_GET_ENTRIES entries whose default is 64.
 *
 * The function can receive three types of input:
 *
 *   - 1) get information for current MAC + vlan - you should
 *      insert MAC+VLAN data in the key variable. data_cnt_p
 *      should be equal to 1. cmd should be
 *      SX_ACCESS_CMD_GET.
 *
 *   - 2) get a list of first n<=64 MACs - data_cnt_p
 *      should be equal to n. mac_type is the type you want to receive.
 *      key_filter_p is the filter type(s) you want to filter the results by.
 *      cmd should be SX_ACCESS_CMD_GET_FIRST.
 *
 *   - 3) get a list of n<=64 MACs which comes after certain
 *      MAC record (it does not have to exist) you should insert
 *      MAC+VLAN data in the key variable. data_cnt_p should be
 *      equal to n. mac_type is the type you want to receive.
 *      key_filter_p is the filter type(s) you want to filter the results by.
 *      cmd should be SX_ACCESS_CMD_GETNEXT.
 *
 *  mac_list_p returns the records info and their quantity in data_cnt_p
 *  for all types of requests.
 *
 *  When in 802.1D mode, instead of providing a vid(Vlan ID) or fid (filtering ID)
 *  in key_p->fid_vid and fid in key_filter_p->fid, you should provide a bridge_id.
 *  bridge_id's will be stored in mac_list_p->fid_vid
 *
 *
 * @param[in] handle         - SX-API handle
 * @param[in] swid           - virtual switch partition ID
 * @param[in] cmd            - get, get_next, get first
 * @param[in] mac_type       - static, dynamic, all
 * @param[in] key_p          - MAC entry with information for search (MAC+FID)
 * @param[in] key_filter_p   - filter types used on the mac_list_p - FID/MAC/logical port
 * @param[out] mac_list_p    - pointer to list
 * @param[in,out] data_cnt_p - number of entries to retrieve, also retrieved
 *                             number of entries
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_mac_addr_get(const sx_api_handle_t              handle,
                                       const sx_swid_t                    swid,
                                       const sx_access_cmd_t              cmd,
                                       const sx_fdb_uc_mac_entry_type_t   mac_type,
                                       const sx_fdb_uc_mac_addr_params_t *key_p,
                                       const sx_fdb_uc_key_filter_t      *key_filter_p,
                                       sx_fdb_uc_mac_addr_params_t       *mac_list_p,
                                       uint32_t                          *data_cnt_p);

/**
 * This function counts all MAC entries in the SW FDB table (static and dynamic).
 *
 * @param[in] handle      - SX-API handle
 * @param[in] swid        - virtual switch partition id
 * @param[out] data_cnt_p - retrieved number of entries
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if the SWID is out of range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_count_get(const sx_api_handle_t handle,
                                    const sx_swid_t       swid,
                                    uint32_t             *data_cnt_p);

/**
 * This function retrieves the amount of MACs learned on a port (static and dynamic).
 *
 * @param[in] handle       - SX-API handle
 * @param[in] log_port     - logical port ID
 * @param[out] data_cnt_p  - retrieved number of entries
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_MESSAGE_SIZE_ZERO if message size is zero
 * @return SX_STATUS_MESSAGE_SIZE_EXCEEDS_LIMIT if message size exceeds limit
 * @return SX_STATUS_INVALID_HANDLE for an invalid handle
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_port_count_get(const sx_api_handle_t  handle,
                                         const sx_port_log_id_t log_port,
                                         uint32_t              *data_cnt_p);

/**
 * This function retrieves the amount of MACs learned on an FID (static and dynamic).
 *
 *  When in 802.1D mode, instead of providing a fid (filtering ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle       - SX-API handle
 * @param[in] swid         - virtual switch partition ID
 * @param[in] fid          - filtering DB ID
 * @param[out] data_cnt_p  - retrieved number of entries
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_MESSAGE_SIZE_ZERO if message size is zero
 * @return SX_STATUS_MESSAGE_SIZE_EXCEEDS_LIMIT if message size exceeds limit
 * @return SX_STATUS_INVALID_HANDLE for an invalid handle
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if FID/SWID is out of range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_fid_count_get(const sx_api_handle_t handle,
                                        const sx_swid_t       swid,
                                        const sx_fid_t        fid,
                                        uint32_t             *data_cnt_p);

/**
 * This function sets/removes the limit on the amount of dynamic MACs learned on a port.
 *
 * @param[in] handle     - SX-API handle
 * @param[in] cmd        - SET/DELETE
 * @param[in] log_port   - logical port ID
 * @param[in] limit      - when SET command is used, this is the new limit to set
 *                         (between 0 and SX_FDB_MAX_ENTRIES)
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_MESSAGE_SIZE_ZERO if message size is zero
 * @return SX_STATUS_MESSAGE_SIZE_EXCEEDS_LIMIT if message size exceeds limit
 * @return SX_STATUS_INVALID_HANDLE for an invalid handle
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if limit is out of range
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_limit_port_set(const sx_api_handle_t  handle,
                                         const sx_access_cmd_t  cmd,
                                         const sx_port_log_id_t log_port,
                                         const uint32_t         limit);

/**
 * This function retrieves the maximum amount of dynamic MACs that can be learned on a port.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] log_port  - logical port ID
 * @param[out] limit_p  - the result limit. If no limit is set SX_FDB_MAX_ENTRIES is returned.
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_MESSAGE_SIZE_ZERO if message size is zero
 * @return SX_STATUS_MESSAGE_SIZE_EXCEEDS_LIMIT if message size exceeds limit
 * @return SX_STATUS_INVALID_HANDLE for an invalid handle
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_limit_port_get(const sx_api_handle_t  handle,
                                         const sx_port_log_id_t log_port,
                                         uint32_t              *limit_p);

/**
 * This function sets/removes the limit on the amount of dynamic MACs learned on FID.
 *
 *  When in 802.1D mode, instead of providing a fid (filtering ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] cmd       - SET/DELETE
 * @param[in] swid      - virtual switch partition ID
 * @param[in] fid       - filtering DB ID
 * @param[in] limit     - when SET command is used, this is the new limit to set
 *                        (between 0 and SX_FDB_MAX_ENTRIES)
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_MESSAGE_SIZE_ZERO if message size is zero
 * @return SX_STATUS_MESSAGE_SIZE_EXCEEDS_LIMIT if message size exceeds limit
 * @return SX_STATUS_INVALID_HANDLE for an invalid handle
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if the SWID/FID/limit is out of range
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_limit_fid_set(const sx_api_handle_t handle,
                                        const sx_access_cmd_t cmd,
                                        const sx_swid_t       swid,
                                        const sx_fid_t        fid,
                                        const uint32_t        limit);

/**
 * This function retrieves the maximum amount of dynamic MACs that can be learned on an FID.
 *
 *  When in 802.1D mode, instead of providing a fid (filtering ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] swid      - virtual switch partition ID
 * @param[in] fid       - filtering DB ID
 * @param[out] limit_p  - the result limit. If no limit is set SX_FDB_MAX_ENTRIES is returned.
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_MESSAGE_SIZE_ZERO if message size is zero
 * @return SX_STATUS_MESSAGE_SIZE_EXCEEDS_LIMIT if message size exceeds limit
 * @return SX_STATUS_INVALID_HANDLE for an invalid handle
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if the FID/SWID is out of range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_limit_fid_get(const sx_api_handle_t handle,
                                        const sx_swid_t       swid,
                                        const sx_fid_t        fid,
                                        uint32_t             *limit_p);

/**
 *      This function adds/deletes MC MAC entries from the FDB.
 *      Note: MC entries cannot be created and associated with ports at the same time.
 *
 *      Note: The log_port_list_p list should not contain the
 *             logical port items which are specified as an Ethernet
 *             port and which are members of a LAG port at same time.
 *
 *      When the ADD command is requested this function performs the following:
 *      - checks a MC group is already created and returns FAILURE if yes;
 *      - allocates and stores the MC group;
 *
 *      When the DELETE command is requested this function performs the following
 *      for each leaf device:
 *      - deletes MC FDB records
 *      - deletes FDB MC ID records
 *      - deletes SPGT record
 *      - deletes MC group from MCDB
 *      - returns pgi into the pool
 *
 *      When Edit (add_port) command is requested this function performs
 *      the following:
 *      - updates the MC DB for adding logical ports and LAG ports
 *      - for each leaf device:
 *        - retrieves a list of LAG-member logical ports from LAGLib for
 *          all LAG logical ports which belong to this MC group
 *        - updates the SPGT record for adding the spine, MC members and
 *          LAGs member ports
 *        - adds local ports to FDB MC ID records (if FDB look-up
 *          by MC ID is allowed on leaf devices)
 *
 *      When Edit (delete_port) command is requested this function performs
 *      the following:
 *      - updates MC DB for deleting logical ports and LAG ports
 *      - for each leaf device:
 *        - updates the SPGT record for deleting requested ports
 *          (if logical port is a LAG port then all LAG-member logical ports
 *          are removed);
 *        - removes local ports from FDB MC ID records
 *          (if FDB look up by MC ID is allowed on leaf devices)
 *
 *      When in 802.1D mode, instead of providing a vid (Vlan ID),
 *      you should provide a bridge_id.
 *
 * @param[in] handle           - SX-API handle
 * @param[in] cmd              - add/delete/add port/delete port/test
 * @param[in] swid             - virtual switch partition ID
 * @param[in] vid              - filtering DB ID
 * @param[in] group_addr       - MAC group address
 * @param[in] log_port_list_p  - a pointer to a port list
 * @param[in] port_cnt         - size of port list
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_NO_MEMORY if memory allocation fails
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ENTRY_ALREADY_EXISTS if group_addr is already added
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_mc_mac_addr_set(const sx_api_handle_t   handle,
                                       const sx_access_cmd_t   cmd,
                                       const sx_swid_t         swid,
                                       const sx_vid_t          vid,
                                       const sx_mac_addr_t     group_addr,
                                       const sx_port_log_id_t* log_port_list_p,
                                       const uint32_t          port_cnt);

/**
 *  This function retrieves MC MAC entries data.
 *  NOTE: The log_port_list_p list contains LAG-port IDs
 *  only and does not contain LAG members' logical-port IDs.
 *
 *  When in 802.1D mode, instead of providing a vid (Vlan ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] swid              - virtual switch partition ID
 * @param[in] vid               - filtering DB ID
 * @param[in] group_addr        - MAC group address
 * @param[out] log_port_list_p  - a pointer to a port list
 * @param[in,out] port_cnt_p    - size of port list
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_NO_MEMORY if memory allocation fails
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_mc_mac_addr_get(const sx_api_handle_t handle,
                                       const sx_swid_t       swid,
                                       const sx_vid_t        vid,
                                       const sx_mac_addr_t   group_addr,
                                       sx_port_log_id_t     *log_port_list_p,
                                       uint32_t             *port_cnt_p);

/**
 *  This function deletes all FDB table entries on a switch partition.
 *
 * @param[in] handle  - SX-API handle
 * @param[in] swid    - virtual switch partition id
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_flush_all_set(const sx_api_handle_t handle,
                                        const sx_swid_t       swid);

/**
 *  This function deletes the FDB table entries that are related to
 *  a flushed port.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] log_port  - logical port.
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_flush_port_set(const sx_api_handle_t  handle,
                                         const sx_port_log_id_t log_port);

/**
 *  This function deletes all FDB table entries that were learned
 *  on the flushed FID.
 *
 *  When in 802.1D mode, instead of providing a fid (filtering ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle  - SX-API handle
 * @param[in] swid    - virtual switch partition ID
 * @param[in] fid     - filtering DB ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_flush_fid_set(const sx_api_handle_t handle,
                                        const sx_swid_t       swid,
                                        const sx_fid_t        fid);

/**
 *  This function deletes all FDB table entries that were learned
 *  on the flushed FID and port.
 *
 *  When in 802.1D mode, instead of providing a fid (filtering ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] log_port  - logical port
 * @param[in] fid       - filtering DB ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_uc_flush_port_fid_set(const sx_api_handle_t  handle,
                                             const sx_port_log_id_t log_port,
                                             const sx_fid_t         fid);

/**
 *  This function deletes all FDB MC tables on a switch partition.
 *
 * @param[in] handle  - SX-API handle
 * @param[in] swid    - virtual switch partition ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_mc_flush_all_set(const sx_api_handle_t handle,
                                        const sx_swid_t       swid);

/**
 *  This function deletes all FDB MC table entries that were
 *  learned on the flushed FID on a switch partition.
 *
 *  When in 802.1D mode, instead of providing a fid (filtering ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle  - SX-API handle
 * @param[in] swid    - virtual switch partition ID
 * @param[in] fid     - filtering DB ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_mc_flush_fid_set(const sx_api_handle_t handle,
                                        const sx_swid_t       swid,
                                        const sx_fid_t        fid);

/**
 *  This function maps VLANs to filtering databases for shared
 *  VLAN learning (SVL) between VLANs. If independent VLAN
 *  learning is desired, a single VLAN should be mapped to a
 *  single FID.
 *
 *  When cmd=add This function adds FID to VID mapping record
 *  to the selected SWID.
 *  When cmd=delete This function deletes FID to VID mapping
 *  record from the selected SWID.
 *  The DEF_FID value is added to the corresponding VLAN.
 *
 *  NOTE: This API performs FDB flushing by FID
 *        before FID to VID mapping changing
 *
 *  NOTE: Only independent learning is supported in the current release.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle       - SX-API handle
 * @param[in] cmd          - add/delete
 * @param[in] swid         - virtual switch partition ID
 * @param[in] fid          - filtering DB ID
 * @param[in] vid          - VLAN ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_fid_vlan_member_set(const sx_api_handle_t handle,
                                           const sx_access_cmd_t cmd,
                                           const sx_swid_t       swid,
                                           const sx_fid_t        fid,
                                           const sx_vid_t        vid);

/**
 *  This API sets the SWID's learning parameters into the system's DB.
 *
 *  NOTE: Only independent learning is supported in the current release.
 *
 * @param[in] handle       - SX-API handle
 * @param[in] swid         - switch (virtual) ID (whose parameters to set)
 * @param[in] learn_ctrl   - is independent/shared learning and is roaming enabled/disabled
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_global_params_set(const sx_api_handle_t     handle,
                                         const sx_swid_t           swid,
                                         const sx_fdb_learn_ctrl_t learn_ctrl);

/**
 *  This API retrieves the SWID's learning parameters from the system's DB.
 *
 * @param[in] handle          - SX-API handle
 * @param[in] swid            - Switch (virtual) ID (whose parameters to retrieve)
 * @param[out] learn_ctrl_p   - Is independent/shared learning and is roaming enabled/disabled
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_global_params_get(const sx_api_handle_t handle,
                                         const sx_swid_t       swid,
                                         sx_fdb_learn_ctrl_t  *learn_ctrl_p);

/**
 *  This function sets the FDB learning mode per SWID
 *  affecting all ports and VLANs in the SWID.
 *
 * @param[in] handle       - SX-API handle
 * @param[in] swid         - virtual switch partition ID
 * @param[in] learn_mode   - new SWID's learn mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_NO_MEMORY if memory allocation fails
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_learn_mode_set(const sx_api_handle_t     handle,
                                      const sx_swid_t           swid,
                                      const sx_fdb_learn_mode_t learn_mode);

/**
 *  This function retrieves the FDB learning mode per SWID.
 *
 * @param[in] handle        - SX-API handle
 * @param[in] swid          - virtual switch partition ID
 * @param[out] learn_mode_p - SWID's learn mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_NO_MEMORY if memory allocation fails
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_learn_mode_get(const sx_api_handle_t handle,
                                      const sx_swid_t       swid,
                                      sx_fdb_learn_mode_t  *learn_mode_p);

/**
 *  This function sets FID's learn mode.
 *
 * @param[in] handle      - SX-API handle
 * @param[in] swid        - switch ID
 * @param[in] fid         - filtering identifier
 * @param[in] learn_mode  - FID's learn mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_fid_learn_mode_set(const sx_api_handle_t     handle,
                                          const sx_swid_t           swid,
                                          const sx_fid_t            fid,
                                          const sx_fdb_learn_mode_t learn_mode);

/**
 *  This function gets fid's learn mode.
 *
 * @param[in] handle        - SX-API handle
 * @param[in] swid          - switch ID
 * @param[in] fid           - filtering identifier
 * @param[out] learn_mode_p - FID's learn mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_fid_learn_mode_get(const sx_api_handle_t handle,
                                          const sx_swid_t       swid,
                                          const sx_fid_t        fid,
                                          sx_fdb_learn_mode_t  *learn_mode_p);

/**
 *  This function sets port's learn mode.
 *
 * @param[in] handle      - SX-API handle
 * @param[in] log_port    - logical port number
 * @param[in] learn_mode  - port's learn mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_port_learn_mode_set(const sx_api_handle_t     handle,
                                           const sx_port_log_id_t    log_port,
                                           const sx_fdb_learn_mode_t learn_mode);

/**
 *  This function gets port's learn mode.
 *
 * @param[in] handle        - SX-API handle
 * @param[in] log_port      - logical port number
 * @param[out] learn_mode_p - port's learn mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_port_learn_mode_get(const sx_api_handle_t  handle,
                                           const sx_port_log_id_t log_port,
                                           sx_fdb_learn_mode_t   *learn_mode_p);

/**
 *  This function sets FDB notify parameters.
 *  Note: Only takes effect when controlled learn mode is set.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] swid              - virtual switch partition ID
 * @param[in] notify_params_p   - new notify params
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_notify_params_set(const sx_api_handle_t         handle,
                                         const sx_swid_t               swid,
                                         const sx_fdb_notify_params_t *notify_params_p);

/**
 *  This function gets FDB notify parameters.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] swid              - virtual switch partition id
 * @param[out] notify_params_p  - swid's notify params
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameter exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_fdb_notify_params_get(const sx_api_handle_t   handle,
                                         const sx_swid_t         swid,
                                         sx_fdb_notify_params_t *notify_params_p);

#endif /* __SX_API_FDB_H__ */
