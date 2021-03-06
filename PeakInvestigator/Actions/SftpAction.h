// --------------------------------------------------------------------------
//  PeakInvestigator-API -- C++ library for accessing the public API of
//                              PeakInvestigator.
// --------------------------------------------------------------------------
// Copyright Veritomyx, Inc. 2016.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Adam Tenderholt $
// $Author: Adam Tenderholt $
// --------------------------------------------------------------------------
//
//

#ifndef SFTP_ACTION_H
#define SFTP_ACTION_H

#include <string>
#include <map>
#include <vector>

#include <PeakInvestigator/PeakInvestigatorSaaS_export.h>
#include "BaseAction.h"

namespace Veritomyx
{

  namespace PeakInvestigator
  {

    class PEAKINVESTIGATORSAAS_EXPORT SftpFingerprints : public std::map<std::string, std::string> {
      public:
        std::vector<std::string> getAlgorithms();
        std::string getHash(std::string algorithm);
    };

    class PEAKINVESTIGATORSAAS_EXPORT SftpAction : public BaseAction
    {
      private:
        int project_ID_;
        SftpFingerprints fingerprints_;

      public:
        static const std::string EXAMPLE_RESPONSE;

        SftpAction(std::string user, std::string code, int project_ID);
        SftpAction(const SftpAction& action);
        virtual ~SftpAction() {}

        std::string buildQuery() const;

        void preCheck();

        virtual std::string getHost();

        virtual int getPort();

        virtual std::string getDirectory();

        virtual std::string getSftpUsername();

        virtual std::string getSftpPassword();

        virtual SftpFingerprints getFingerprints();

        std::string getErrorMessage();

        int getErrorCode();
    };

  }

}

#endif // SFTP_ACTION_H
