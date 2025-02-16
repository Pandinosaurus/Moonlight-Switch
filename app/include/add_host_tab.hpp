//
//  add_host_tab.hpp
//  Moonlight
//
//  Created by XITRIX on 26.05.2021.
//

#pragma once

#include <borealis.hpp>
#include "Settings.hpp"
#include "GameStreamClient.hpp"

class AddHostTab : public brls::Box
{
  public:
    AddHostTab();
    ~AddHostTab() override;

    static brls::View* create();

  private:
    void findHost();
    void stopSearchHost();
    void connectHost(const std::string& address);
    void fillSearchBox(const GSResult<std::vector<Host>>& hostsRes);
    static void pauseSearching();
    static void startSearching();
    brls::Event<GSResult<std::vector<Host>>>::Subscription searchSubscription;

    bool searchBoxIpExists(const std::string& ip);
    
    BRLS_BIND(brls::InputCell, hostIP, "hostIP");
    BRLS_BIND(brls::DetailCell, connect, "connect");
    BRLS_BIND(brls::Box, searchBox, "search_box");
    BRLS_BIND(brls::Box, loader, "loader");
    BRLS_BIND(brls::Header, searchHeader, "search_header");
};
