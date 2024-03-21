/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2015 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XAM_APPS_XLIVEBASE_APP_H_
#define XENIA_KERNEL_XAM_APPS_XLIVEBASE_APP_H_

#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/xam/app_manager.h"

namespace xe {
namespace kernel {
namespace xam {
namespace apps {

class XLiveBaseApp : public App {
 public:
  explicit XLiveBaseApp(KernelState* kernel_state);

  X_HRESULT DispatchMessageSync(uint32_t message, uint32_t buffer_ptr,
                                uint32_t buffer_length) override;

 private:
  X_HRESULT GetServiceInfo(uint32_t service_id, uint32_t service_info);

  X_HRESULT CreateFriendsEnumerator(uint32_t buffer_args);
  X_HRESULT XStringVerify(uint32_t buffer_ptr, uint32_t buffer_length);
  X_HRESULT XStorageDownloadToMemory(uint32_t buffer_ptr);
  X_HRESULT XStorageUploadFromMemory(uint32_t buffer_ptr);
  X_HRESULT XStorageBuildServerPath(uint32_t buffer_ptr);
};

}  // namespace apps
}  // namespace xam
}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_XAM_APPS_XLIVEBASE_APP_H_
