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

#ifndef __SX_API_VLAN_H__
#define __SX_API_VLAN_H__

#include <sx/sdk/sx_api.h>


/************************************************
 *  API functions
 ***********************************************/

/**
 * This function sets the log verbosity level of VLAN MODULE
 * @param[in] handle                   - SX-API handle
 * @param[in] verbosity_target         - set verbosity of : API / MODULE / BOTH
 * @param[in] module_verbosity_level   - VLAN module verbosity level
 * @param[in] api_verbosity_level      - VLAN API verbosity level
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 *         SX_STATUS_PARAM_ERROR if any input parameters is invalid
 *         SX_STATUS_ERROR general error
 */
sx_status_t sx_api_vlan_log_verbosity_level_set(const sx_api_handle_t           handle,
                                                const sx_log_verbosity_target_t verbosity_target,
                                                const sx_verbosity_level_t      module_verbosity_level,
                                                const sx_verbosity_level_t      api_verbosity_level);

/**
 * This function gets the log verbosity level of VLAN MODULE
 *
 * @param[in]  handle                   - SX-API handle
 * @param[in]  verbosity_target         - get verbosity of : API / MODULE / BOTH
 * @param[out] module_verbosity_level_p - VLAN module verbosity level
 * @param[out] api_verbosity_level_p    - VLAN API verbosity level
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 *         SX_STATUS_PARAM_ERROR if any input parameters is invalid
 *         SX_STATUS_ERROR general error
 */
sx_status_t sx_api_vlan_log_verbosity_level_get(const sx_api_handle_t           handle,
                                                const sx_log_verbosity_target_t verbosity_target,
                                                sx_verbosity_level_t           *module_verbosity_level_p,
                                                sx_verbosity_level_t           *api_verbosity_level_p);

/**
 *  This API sets the VLAN member ports.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] cmd               - ADD/DELETE/DELETE_ALL
 * @param[in] swid              - virtual switch partition ID
 * @param[in] vid               - VLAN ID
 * @param[in] vlan_port_list_p  - a pointer to array of port list
 *                                structure. Each port in the list has its logical port
 *                                number and the egress filter mode (tagged/ untagged and
 *                                priority tagged member). If DELETE_ALL command is used
 *                                port_cnt = 0, vlan_port_list_p = NULL are applicable
 * @param[in] port_cnt          - number of ports in a port list
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_CMD_UNSUPPORTED if unsupported command is requested
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_NO_RESOURCES if the pool cannot provide object
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_ports_set(const sx_api_handle_t  handle,
                                  const sx_access_cmd_t  cmd,
                                  const sx_swid_t        swid,
                                  const sx_vid_t         vid,
                                  const sx_vlan_ports_t *vlan_port_list_p,
                                  const uint32_t         port_cnt);

/**
 *  This API retrieves the VLAN member ports.
 *  NOTE: If port_cnt_p is set as less than actual number of ports,
 *        the first port_cnt_p elements in array, and successful result
 *        are returned as output.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle               - SX-API handle
 * @param[in] swid                 - virtual switch partition ID
 * @param[in] vid                  - VLAN ID
 * @param[in,out] vlan_port_list_p - a pointer to array of VLAN port list structure.
 *                                   If it is NULL, the port_cnt_p variable is filled out
 *                                   with numbers of ports that could be retrieved. If
 *                                   the pointer is valid, VLAN ports are placed there
 *                                   and port_cnt_p takes actual number ports in array.
 * @param[in,out] port_cnt_p       - number of ports in a list that you want to retrieve
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_ERROR for a general error
 * @return SX_STATUS_CMD_UNSUPPORTED if 802.1D mode is enabled
 */
sx_status_t sx_api_vlan_ports_get(const sx_api_handle_t handle,
                                  const sx_swid_t       swid,
                                  const sx_vid_t        vid,
                                  sx_vlan_ports_t      *vlan_port_list_p,
                                  uint32_t             *port_cnt_p);

/**
 *  This API sets the VLANs list to a port in a single command.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle         - SX-API handle
 * @param[in] cmd            - SX_ACCESS_CMD_ADD - add list of VLANs to port
 *                             SX_ACCESS_CMD_DELETE - remove a list VLANs from port
 * @param[in] log_port       - logical port
 * @param[in] vlan_list_p    - pointer to a VLANs list
 * @param[in] vlan_cnt       - size of VLANs list
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_CMD_UNSUPPORTED if command is not supported
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_NO_RESOURCES if the pool cannot provide object
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_multi_vlan_set(const sx_api_handle_t  handle,
                                            const sx_access_cmd_t  cmd,
                                            const sx_port_log_id_t log_port,
                                            const sx_port_vlans_t *vlan_list_p,
                                            const uint32_t         vlan_cnt);

/**
 *  This API sets the priority tagged attribute per port.
 *
 * @param[in] handle                - SX-API handle
 * @param[in] log_port              - logical port
 * @param[in] untagged_prio_state   - untagged packets are sent priority-tagged or not
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameters exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_NO_RESOURCES if the pool cannot provide object
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_prio_tagged_set(const sx_api_handle_t          handle,
                                             const sx_port_log_id_t         log_port,
                                             const sx_untagged_prio_state_t untagged_prio_state);

/**
 *  This API retrieves the priority tagged attribute per port.
 *
 * @param[in] handle                    - SX-API handle
 * @param[in] log_port                  - logical port
 * @param[out] untagged_prio_state_p    - untagged packets are sent
 *                                        priority-tagged or not
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_prio_tagged_get(const sx_api_handle_t     handle,
                                             const sx_port_log_id_t    log_port,
                                             sx_untagged_prio_state_t *untagged_prio_state_p);

/**
 *   This API enables/disables ingress VLAN filtering on a port
 *   The VLAN membership is defined in sx_vlan_ports_set API.
 *
 *   This function is only valid when in 802.1Q mode.
 *
 *  @param[in] handle              - SX-API handle
 *  @param[in] log_port            - logical port number
 *  @param[in] ingress_filter_mode - port ingress VLAN filter
 *                                   mode (enable/disable)
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_CMD_UNSUPPORTED if unsupported access command is requested
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_ingr_filter_set(const sx_api_handle_t       handle,
                                             const sx_port_log_id_t      log_port,
                                             const sx_ingr_filter_mode_t ingress_filter_mode);

/**
 *   This API retrieves ingress VLAN filtering on a port.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 *  @param[in] handle                  - SX-API handle
 *  @param[in] log_port                - logical port number
 *  @param[out] ingress_filter_state_p - a pointer to port ingress VLAN
 *                                       filter state (enable/disable)
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_ERROR for a general error
 * @return SX_STATUS_CMD_UNSUPPORTED if 802.1D mode is enabled
 */
sx_status_t sx_api_vlan_port_ingr_filter_get(const sx_api_handle_t  handle,
                                             const sx_port_log_id_t log_port,
                                             sx_ingr_filter_mode_t *ingress_filter_mode_p);

/**
 *  This API sets port's default VLAN ID. The PVID is set to
 *  untagged packets that ingress on the port.
 *  Note: When the PVID is deleted from the port, it is assigned
 *  with the default VLAN ID.
 *
 * @param[in] handle   - SX-API handle
 * @param[in] cmd      - ADD/DELETE
 * @param[in] log_port - logical port number
 * @param[in] pvid     - port VLAN ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_pvid_set(const sx_api_handle_t  handle,
                                      const sx_access_cmd_t  cmd,
                                      const sx_port_log_id_t log_port,
                                      const sx_vid_t         pvid);

/**
 *  This API retrieves port's default VLAN ID.
 *
 * @param[in] handle   - SX-API handle
 * @param[in] log_port - logical port number
 * @param[out] pvid_p  - Port VLAN ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_pvid_get(const sx_api_handle_t  handle,
                                      const sx_port_log_id_t log_port,
                                      sx_vid_t              *pvid_p);

/**
 *  This API sets a port's accepted frame types.
 *  Note: By default, all ports are configured to accept all
 *  frame types
 *  Note: Priority tagged packets are considered as untagged
 *  packets
 *
 * @param[in] handle             - SX-API handle
 * @param[in] log_port           - logical port number
 * @param[in] accptd_frm_types_p - struct holding the following values:
 *                                  allow_tagged, allow_untagged,
 *                                 allow_prio_tagged
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_accptd_frm_types_set(const sx_api_handle_t        handle,
                                                  const sx_port_log_id_t       log_port,
                                                  const sx_vlan_frame_types_t *accptd_frm_types_p);

/**
 *  This API retrieves a port's accepted frame types.
 *
 * @param[in] handle              - SX-API handle
 * @param[in] log_port            - logical port number
 * @param[out] accptd_frm_types_p - a pointer to struct holding the following
 *                                 values: allow_tagged, allow_untagged,
 *                                 allow_prio_tagged
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_PARAM_NULL if a parameter is NULL
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameters exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_accptd_frm_types_get(const sx_api_handle_t  handle,
                                                  const sx_port_log_id_t log_port,
                                                  sx_vlan_frame_types_t *accptd_frm_types_p);

/**
 *  This API sets the virtual switch's default VLAN ID. This
 *  VID is set by default as the PVID of all switch ports. If
 *  not called, the default VID for all virtual switches is 1.
 *
 * @param[in] handle - SX-API handle
 * @param[in] swid   - virtual switch partition ID
 * @param[in] vid    - switch default VLAN ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ACCESS_CMD_UNSUPPORTED if unsupported access command is requested
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_default_vid_set(const sx_api_handle_t handle,
                                        const sx_swid_t       swid,
                                        const sx_vid_t        vid);

/**
 *  This API gets the virtual switch's default VLAN ID. This
 *  VID is set by default as the PVID of all switch ports. If
 *  not called, the default VID for all virtual switches is 1.
 *
 * @param[in] handle - SX-API handle
 * @param[in] swid   - virtual switch partition ID
 * @param[out] vid    - switch default VLAN ID
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ACCESS_CMD_UNSUPPORTED if unsupported access command is requested
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_NO_MEMORY if problems with memory allocation occur
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 * @return SX_STATUS_PARAM_NULL if parameter is NULL.
 */
sx_status_t sx_api_vlan_default_vid_get(const sx_api_handle_t handle,
                                        const sx_swid_t       swid,
                                        sx_vid_t             *vid);

/**
 *  This API sets unregistered MC flood mode.
 *
 *  When in 802.1D mode, instead of providing a vid(Vlan ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] swid              - virtual switch partition ID
 * @param[in] vid               - VLAN ID
 * @param[in] urmc_flood_mode   - unregistered MC flood mode: FLOOD / PRUNE
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_unreg_mc_flood_mode_set(const sx_api_handle_t            handle,
                                                const sx_swid_t                  swid,
                                                const sx_vid_t                   vid,
                                                const sx_vlan_unreg_flood_mode_t urmc_flood_mode);

/**
 *  This API retrieves unregistered MC flood mode.
 *
 *  When in 802.1D mode, instead of providing a vid(Vlan ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle                 - SX-API handle
 * @param[in] swid                   - virtual switch partition ID
 * @param[in] vid                    - VLAN ID
 * @param[out] urmc_flood_mode_p     - unregister MC flood mode: FLOOD / PRUNE
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_unreg_mc_flood_mode_get(const sx_api_handle_t       handle,
                                                const sx_swid_t             swid,
                                                const sx_vid_t              vid,
                                                sx_vlan_unreg_flood_mode_t *urmc_flood_mode_p);

/**
 *  This API sets unregistered MC flood ports.
 *
 *  When in 802.1D mode, instead of providing a vid(Vlan ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] swid              - virtual switch partition ID
 * @param[in] vid               - VLAN ID
 * @param[in] log_port_list_p   - a pointer to a port list, port may be a LAG or physical port
 * @param[in] port_cnt          - size of port list
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_unreg_mc_flood_ports_set(const sx_api_handle_t   handle,
                                                 const sx_swid_t         swid,
                                                 const sx_vid_t          vid,
                                                 const sx_port_log_id_t *log_port_list_p,
                                                 const uint32_t          port_cnt);

/**
 *  This API retrieves unregistered MC flood ports.
 *
 *  When in 802.1D mode, instead of providing a vid(Vlan ID),
 *  you should provide a bridge_id.
 *
 * @param[in] handle            - SX-API handle
 * @param[in] swid              - virtual switch partition ID
 * @param[in] vid               - VLAN ID
 * @param[out] log_port_list_p  - a pointer to a port list, port can be LAG or physical port
 * @param[in,out] port_cnt_p    - size of port list
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in the DB
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_unreg_mc_flood_ports_get(const sx_api_handle_t handle,
                                                 const sx_swid_t       swid,
                                                 const sx_vid_t        vid,
                                                 sx_port_log_id_t     *log_port_list_p,
                                                 uint32_t             *port_cnt_p);

/**
 *  This API sets Q-in-Q mode of port.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] log_port  - logical port ID
 * @param[in] qinq_mode - mode: Q-in-Q enabled/disabled
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameters exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_ERROR for a general error
 * @return SX_STATUS_CMD_UNSUPPORTED if 802.1D mode is enabled
 */
sx_status_t sx_api_vlan_port_qinq_mode_set(const sx_api_handle_t  handle,
                                           const sx_port_log_id_t log_port,
                                           const sx_qinq_mode_t   qinq_mode);

/**
 *  This API retrieves Q-in-Q mode of port.
 *
 *  This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle        - SX-API handle
 * @param[in] log_port      - logical port ID
 * @param[out] qinq_mode_p  - the retrieved mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_CMD_UNSUPPORTED if 802.1D mode is enabled
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_qinq_mode_get(const sx_api_handle_t  handle,
                                           const sx_port_log_id_t log_port,
                                           sx_qinq_mode_t        *qinq_mode_p);

/**
 * The API sets which priority should be taken for the outer tag (when Q-in-Q is enabled):
 * The port's default priority, or the inner tag's priority.
 *
 * This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle    - SX-API handle
 * @param[in] log_port  - logical port ID
 * @param[in] prio_mode - mode: default/inner priority
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if a NULL handle is received
 * @return SX_STATUS_PARAM_ERROR if an input parameter is invalid
 * @return SX_STATUS_PARAM_EXCEEDS_RANGE if a parameters exceeds its range
 * @return SX_STATUS_ENTRY_NOT_FOUND if a requested element is not found in DB
 * @return SX_STATUS_SXD_RETURNED_NON_ZERO if SxD driver function fails
 * @return SX_STATUS_CMD_UNSUPPORTED if 802.1D mode is enabled
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_qinq_outer_prio_mode_set(const sx_api_handle_t           handle,
                                                      const sx_port_log_id_t          log_port,
                                                      const sx_qinq_outer_prio_mode_t prio_mode);

/**
 * This API retrieves port's Q-in-Q outer tag priority mode.
 *
 * This function is only valid when in 802.1Q mode.
 *
 * @param[in] handle       - SX-API handle
 * @param[in] log_port     - logical port ID
 * @param[out] prio_mode_p - the retrieved mode
 *
 * @return SX_STATUS_SUCCESS if operation completes successfully
 * @return SX_STATUS_INVALID_HANDLE if handle is invalid
 * @return SX_STATUS_PARAM_ERROR if any input parameter is invalid
 * @return SX_STATUS_ENTRY_NOT_FOUND if requested element is not found in DB
 * @return SX_STATUS_CMD_UNSUPPORTED if 802.1D mode is enabled
 * @return SX_STATUS_ERROR for a general error
 */
sx_status_t sx_api_vlan_port_qinq_outer_prio_mode_get(const sx_api_handle_t      handle,
                                                      const sx_port_log_id_t     log_port,
                                                      sx_qinq_outer_prio_mode_t *prio_mode_p);


#endif /* __SX_API_VLAN_H__ */
