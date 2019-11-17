#include <utility>

#include <actor-zeta/detail/string_view.hpp>
#include <actor-zeta/actor/actor_address.hpp>
#include <actor-zeta/messaging/message_header.hpp>

namespace actor_zeta { namespace messaging {

        auto message_header::command() const noexcept -> detail::string_view {
            return detail::string_view(command_.data(),command_.size());
        }

        message_header::message_header(actor::actor_address sender_, std::string name)
                :sender_(std::move(sender_)), command_(std::move(name)) {}

        auto message_header::sender() const -> actor::actor_address {
            return sender_;
        }

}}