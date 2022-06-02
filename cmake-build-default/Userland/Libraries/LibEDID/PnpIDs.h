
#pragma once

#include <AK/Function.h>
#include <AK/StringView.h>
#include <AK/Types.h>

namespace PnpIDs {
    struct PnpIDData {
        StringView manufacturer_id;
        StringView manufacturer_name;
        struct {
            u16 year{};
            u8 month{};
            u8 day{};
        } approval_date;
    };

    Optional<PnpIDData> find_by_manufacturer_id(StringView);
    IterationDecision for_each(Function<IterationDecision(PnpIDData const&)>);
    static constexpr size_t count = 2498;
}
