/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:*
 * Copyright 2023 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "wan_hal.h"

int wan_hal_Init(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int wan_hal_SetWanmode(t_eWanMode mode)
{
  /*TODO: Implement Me!*/
  (void)mode;
  return (int)0;
}

int wan_hal_SetWanConnectionEnable(unsigned int enable)
{
  /*TODO: Implement Me!*/
  (void)enable;
  return (int)0;
}

int wan_hal_SetSelfHealConfig(PSELFHEAL_CONFIG pSelfHealConfig)
{
  /*TODO: Implement Me!*/
  (void)pSelfHealConfig;
  return (int)0;
}

int wan_hal_GetWanOEUpstreamCurrRate(unsigned int *pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (int)0;
}

int wan_hal_GetWanOEDownstreamCurrRate(unsigned int *pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (int)0;
}

int wan_hal_SetQoSConfiguration(PWAN_QOS_QUEUE pQueue, unsigned int QueueNumberOfEntries, const char *baseifname, const char *wanifname)
{
  /*TODO: Implement Me!*/
  (void)pQueue;
  (void)QueueNumberOfEntries;
  (void)baseifname;
  (void)wanifname;
  return (int)0;
}

int wan_hal_ConfigureIpv4(PWAN_IPV4_CFG pWanIpv4Cfg)
{
  /*TODO: Implement Me!*/
  (void)pWanIpv4Cfg;
  return (int)0;
}

int wan_hal_UnConfigureIpv4(PWAN_IPV4_CFG pWanIpv4Cfg)
{
  /*TODO: Implement Me!*/
  (void)pWanIpv4Cfg;
  return (int)0;
}

int wan_hal_ConfigureIpv6(PWAN_IPV6_CFG pWanIpv6Cfg)
{
  /*TODO: Implement Me!*/
  (void)pWanIpv6Cfg;
  return (int)0;
}

int wan_hal_UnConfigureIpv6(PWAN_IPV6_CFG pWanIpv6Cfg)
{
  /*TODO: Implement Me!*/
  (void)pWanIpv6Cfg;
  return (int)0;
}

int wan_hal_EnableMapt(PWAN_MAPT_CFG pMAPTCfg)
{
  /*TODO: Implement Me!*/
  (void)pMAPTCfg;
  return (int)0;
}

int wan_hal_DisableMapt(const char *ifName)
{
  /*TODO: Implement Me!*/
  (void)ifName;
  return (int)0;
}

int wan_hal_enableWanOEMode(const unsigned char enable)
{
  /*TODO: Implement Me!*/
  (void)enable;
  return (int)0;
}

int wan_hal_getAuthInfo(char *authInfo)
{
  /*TODO: Implement Me!*/
  (void)authInfo;
  return (int)0;
}
